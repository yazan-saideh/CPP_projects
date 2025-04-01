#ifndef RECOMMENDATIONSYSTEM_H
#define RECOMMENDATIONSYSTEM_H

#include <map>
#include <set>
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include "Movie.h"

class User;



class RecommendationSystem {
private:

  struct MovieComparator {
    bool operator()(const sp_movie& lhs, const sp_movie& rhs) const {
      return *lhs < *rhs;
    }
  };
  std::set<sp_movie, MovieComparator> Movies;
  std::unordered_map<sp_movie, std::vector<double>,
      hash_func, equal_func> movie_features_;
public:
  RecommendationSystem();
  ~RecommendationSystem();
  sp_movie get_movie(const std::string& name, int year);
  sp_movie add_movie_to_rs(const std::string& name,
    int year, const std::vector<double>& features);
  sp_movie recommend_by_content(const User& user_rankings);
  double predict_movie_score(const User& user_rankings,
    const sp_movie& movie, unsigned int k);
  sp_movie recommend_by_cf(const User& user_rankings, int k);
  friend std::ostream& operator<<(std::ostream& os,
    const RecommendationSystem& recommendation_system);
  friend std::ostream& operator<<(std::ostream& os, const User& user);
};

#endif // RECOMMENDATIONSYSTEM_H
