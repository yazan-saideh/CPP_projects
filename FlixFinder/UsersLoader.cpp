#include "UsersLoader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <filesystem>
#include "User.h"
#include "RecommendationSystem.h"
#define FILE_ERROR "Failed to open file: "
#define HEADER_ERROR "Missing header line in file: "
#define INVALID_HEADER "Invalid movie format in header: "
#define INVALID_USER "Invalid user name format in file: "
#define INVALID_MOVIE_INDEX "Missing rating for movie index "
#define INVALID_RATING "Rating out of valid range (1-10) for movie index "
#define MOVIE_NOT_FOUND "Movie not found in recommendation system: "
std::vector<User> UsersLoader::create_users
(const std::string &users_file_path,
    std::shared_ptr<RecommendationSystem> rs) {
    std::ifstream file(users_file_path);
    if (!file.is_open()) {
        throw std::runtime_error(FILE_ERROR + users_file_path +
            " (Resolved absolute path: " +std::filesystem::absolute
                (users_file_path).string() + ")");}
    std::vector<User> users;
    std::vector<std::string> movie_names;
    std::vector<int> movie_years;
    std::string line;
    if (!std::getline(file, line)) {
        throw std::runtime_error(HEADER_ERROR+ users_file_path);}
    std::istringstream header_stream(line);
    std::string movie_name_year;
    while (header_stream >> movie_name_year) {
        size_t dash_pos = movie_name_year.find('-');
        if (dash_pos == std::string::npos) {
            throw std::runtime_error(INVALID_HEADER + movie_name_year);}
        std::string movie_name = movie_name_year.substr(0, dash_pos);
        int movie_year = std::stoi(movie_name_year.substr(dash_pos + 1));
        movie_names.push_back(movie_name);
        movie_years.push_back(movie_year);}
    while (std::getline(file, line)) {
        std::istringstream line_stream(line);
        std::string user_name;
        if (!(line_stream >> user_name)) {
            throw std::runtime_error(INVALID_USER + line);}
        rank_map user_ratings(0, sp_movie_hash, sp_movie_equal);
        for (size_t i = 0; i < movie_names.size(); ++i) {
            std::string rating_str;
            if (!(line_stream >> rating_str)) {
                throw std::runtime_error(INVALID_MOVIE_INDEX +
                    std::to_string(i) + " for user: " + user_name);}
            if (rating_str == "NA") {continue;}
            double rating = std::stod(rating_str);
            if (rating < 1.0 || rating > 10.0) {
                throw std::runtime_error(INVALID_RATING+
                    std::to_string(i) + " for user: " + user_name);}
            sp_movie movie = rs->get_movie(movie_names[i], movie_years[i]);
            if (!movie) {
                throw std::runtime_error(MOVIE_NOT_FOUND+ movie_names[i] +
                    " (" + std::to_string(movie_years[i]) + ")");}
            user_ratings[movie] = rating;}
        User user(user_name, user_ratings, rs);
        users.push_back(user);}
    return users;}
