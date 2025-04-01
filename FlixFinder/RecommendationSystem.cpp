//
// Created by miner on 23/01/2025.
//
#include "RecommendationSystem.h"
#include <complex>
#include <queue>
#include "User.h"
#define RUNTIME_TIME_ERROR_NAME "Error: Movie name cannot be empty."
#define RUNTIME_TIME_ERROR_FEATURES "Error: Movie name cannot be empty."
#define RUNTIME_TIME_ERROR_YEAR "Error: Features cannot be empty for movie: "
RecommendationSystem::RecommendationSystem(): movie_features_
(0, sp_movie_hash, sp_movie_equal){}
RecommendationSystem::~RecommendationSystem() = default;
sp_movie RecommendationSystem::get_movie
(const std::string &name, int year) {
    sp_movie temp = std::make_shared<Movie>(name, year);
    auto it = Movies.find(temp);
    if (it == Movies.end()) {
        return nullptr;
    }
    return *it;
}

sp_movie RecommendationSystem::add_movie_to_rs(
    const std::string &name,int year,
    const std::vector<double> &features) {
    if (name.empty()) {
        throw std::runtime_error
        (RUNTIME_TIME_ERROR_NAME);
    }
    if (features.empty()) {
        throw std::runtime_error
        (RUNTIME_TIME_ERROR_FEATURES + name);
    }
    for (const auto &feature : features) {
        if (feature <= 0.0) {
            throw std::runtime_error
            (RUNTIME_TIME_ERROR_YEAR + name);
        }
    }
    if (!year) {
        throw std::runtime_error
        (RUNTIME_TIME_ERROR_YEAR + name);
    }
    sp_movie movie = get_movie(name, year);
    if (!movie) {
        movie = std::make_shared<Movie>(name, year);
        Movies.insert(movie);
    }
    movie_features_[movie] = features;
    return movie;
}



std::ostream &operator<<(std::ostream &os, const RecommendationSystem &rs) {
    for (const auto &movie : rs.Movies) {
        os << *movie;
    }
    return os;
}
sp_movie RecommendationSystem::recommend_by_content
(const User &user_rankings) {
    if (user_rankings.get_rank().empty()) {
        return nullptr;}
    double total = 0.0;
    int total_movies = 0;
    for (const auto &[movie, rating] :
        user_rankings.get_rank()) {
        total += rating;
        total_movies++;}
    double avg_rating = total / total_movies;
    std::map<sp_movie, double> normalized_ratings;
    for (const auto &[movie, rating]
        : user_rankings.get_rank()) {
        normalized_ratings[movie] = rating - avg_rating;}
    std::vector<double> P_rating
    (movie_features_.begin()->second.size(), 0.0);
    for (const auto &[movie, normalized_rating]
        : normalized_ratings) {
        const std::vector<double> &features = movie_features_.at(movie);
        for (size_t i = 0; i < features.size(); ++i) {
            P_rating[i] += normalized_rating * features[i];}}
    sp_movie best_movie = nullptr;
    double max_similarity = -1.0;
    for (const auto &[movie,
        features] : movie_features_) {
        if (user_rankings.get_rank().find(movie)
            != user_rankings.get_rank().end()) {continue;}
        double sum = 0.0;
        double U_norm = 0.0;
        double V_norm = 0.0;
        for (size_t i = 0; i < features.size(); ++i) {
            sum += features[i] * P_rating[i];
            U_norm += features[i] * features[i];
            V_norm += P_rating[i] * P_rating[i];}
        double W_norm = std::sqrt(U_norm) * std::sqrt(V_norm);
        if (W_norm == 0.0) {continue;}
        double CS_final = sum / W_norm;
        if (CS_final > max_similarity) {
            max_similarity = CS_final;
            best_movie = movie;
        }
    }
    return best_movie;
}

double RecommendationSystem::predict_movie_score
(const User &user_rankings, const sp_movie &movie, unsigned int k) {
    if (user_rankings.get_rank().empty()) {return 0.0; }
    std::multimap<double, sp_movie> similarity_map;
    for (const auto &[rated_movie, rating]
        : user_rankings.get_rank()) {
        const auto &rated_features =
            movie_features_.at(rated_movie);
        const auto &target_features =
            movie_features_.at(movie);
        double dot_product = 0.0;
        double norm_rated = 0.0;
        double norm_target = 0.0;
        for (size_t i = 0; i < rated_features.size(); ++i) {
            dot_product += rated_features[i] * target_features[i];
            norm_rated += rated_features[i] * rated_features[i];
            norm_target += target_features[i] * target_features[i];}
        double norm_product = std::sqrt(norm_rated) * std::sqrt(norm_target);
        double cosine_similarity = (norm_product > 0.0)
        ? (dot_product / norm_product) : 0.0;
        similarity_map.insert({cosine_similarity, rated_movie});}
    while (similarity_map.size() > k) {
        similarity_map.erase(similarity_map.begin());}
    double numerator = 0.0;
    double denominator = 0.0;
    for (const auto &[similarity,
        similar_movie] : similarity_map) {
        double rating = user_rankings.get_rank().at(similar_movie);
        numerator += similarity * rating;
        denominator += similarity;
    }
    return (denominator > 0) ? (numerator / denominator) : 0.0;
}




sp_movie RecommendationSystem::recommend_by_cf
(const User &user_rankings, int k) {
    sp_movie best_movie = nullptr;
    double highest_score = -1.0;
    for (const auto &[movie,
        features] : movie_features_) {
        if (user_rankings.get_rank().find(movie)
            == user_rankings.get_rank().end()) {
            double score = predict_movie_score(user_rankings, movie, k);
            if (score > highest_score) {
                highest_score = score;
                best_movie = movie;
            }
        }
    }
    return best_movie;
}







