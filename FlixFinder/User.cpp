//
// Created by miner on 23/01/2025.
//

#include <sstream>
#include "User.h"
#include "RecommendationSystem.h"

User::User(const std::string& user_name , const rank_map& rank_map,
    std::shared_ptr<RecommendationSystem> recommendation_system)
: user_name(user_name), Rank_map(rank_map),
recommendation_system(recommendation_system) {}
User::~User() = default;
std::string User::get_name() const{
    return user_name;
}

const rank_map& User::get_rank() const {
    return Rank_map;
}
void User::add_movie_to_user(const std::string &name,
    int year, const std::vector<double> &features, double rate) {
    sp_movie movie =
        recommendation_system->add_movie_to_rs(name,year,features);
    Rank_map[movie] = rate;
}
sp_movie User::get_rs_recommendation_by_content() {
    return  recommendation_system->recommend_by_content(*this);
}
double User::get_rs_prediction_score_for_movie
(const std::string &name, int year, unsigned int k) {
    sp_movie movie = recommendation_system->get_movie(name, year);
    if (!movie) {
        throw std::runtime_error("Movie not found: "
            + name + " (" + std::to_string(year) + ")");
    }
    return recommendation_system->predict_movie_score(*this, movie, k);
}
sp_movie User::get_rs_recommendation_by_cf(int k) {
    return recommendation_system->recommend_by_cf(*this,k);
}
std::ostream& operator<<(std::ostream &os, const User &user) {
    os << "name: " << user.get_name() << std::endl;
    if (user.recommendation_system) {
        for (const auto &movie
            :user.recommendation_system->Movies) {
            os << *movie;
        }
    }
    os << std::endl;
    return os;
}



