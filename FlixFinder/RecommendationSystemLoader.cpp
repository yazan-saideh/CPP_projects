#include "RecommendationSystemLoader.h"
#include "RecommendationSystem.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#define FILE_ERROR "Couldn't open file' "
#define MOVIE_ERROR "Error: Missing or invalid movie "\
"name and year separator on line "
#define MOVIE_FILE_ERROR "Error: Invalid year format for movie:  "
#define MOVIE_FRETURE_ERROR "Error: No features provided for movie: "
std::unique_ptr<RecommendationSystem> RecommendationSystemLoader
::create_rs_from_movies(const std::string& path) {
    auto rs = std::make_unique<RecommendationSystem>();
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error(FILE_ERROR + path);
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    for (size_t line_index = 0; line_index <
        lines.size(); ++line_index) {
        std::istringstream iss(lines[line_index]);
        std::string name;
        int year;
        std::vector<double> features;
        if (!std::getline(iss, name, '-')) {
            throw std::runtime_error(MOVIE_ERROR
                + std::to_string(line_index + 1));
        }
        if (!(iss >> year)) {
            throw std::runtime_error(MOVIE_FILE_ERROR+
                name + " on line " + std::to_string(line_index + 1));
        }
        double feature;
        while (iss >> feature) {
            features.push_back(feature);
        }
        if (features.empty()) {
            throw std::runtime_error(MOVIE_FRETURE_ERROR + name
                + " on line " + std::to_string(line_index + 1));
        }
        name.erase(name.find_last_not_of(" \t\n\r\f\v") + 1);
        rs->add_movie_to_rs(name, year, features);
    }
    return rs;
}
