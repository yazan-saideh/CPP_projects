//
// Created on 2/20/2022.
//

#ifndef USER_H
#define USER_H
#include <unordered_map>
#include <vector>
#include <string>
#include "RecommendationSystem.h"

typedef std::unordered_map<sp_movie,
double, hash_func,equal_func> rank_map;

class RecommendationSystem;
class User

{
private:
	std::string user_name;
	rank_map Rank_map;
	std::shared_ptr<RecommendationSystem> recommendation_system;
public:
User(const std::string& user_name,const rank_map& rank_map
	,std::shared_ptr<RecommendationSystem> recommendation_system);
	~User();
std::string get_name() const;

	const rank_map& get_rank() const;
	/**
	 * function for adding a movie to the DB
	 * @param name name of movie
     * @param year year it was made
	 * @param features a vector of the movie's features
	 * @param rate the user rate for this movie
	 */
	void add_movie_to_user(const std::string &name, int year,
                         const std::vector<double> &features,
                         double rate);




	/**
	 * returns a recommendation according to the movie's content
	 * @return recommendation
	 */
	sp_movie get_rs_recommendation_by_content();

	/**
	 * returns a recommendation according to
	 * the similarity recommendation method
	 * @param k the number of the most similar movies to calculate by
	 * @return recommendation
	 */
	sp_movie get_rs_recommendation_by_cf(int k);

	friend std::ostream& operator<<(std::ostream &os, const User& user);

	/**
	 * predicts the score for a given movie
	 * @param name the name of the movie
	 * @param year the year the movie was created
	 * @param k the parameter which represents the
	 * number of the most similar movies to predict the score by
	 * @return predicted score for the given movie
	 */
	double get_rs_prediction_score_for_movie(const
		std::string& name, int year, unsigned int k);


};



#endif //USER_H
