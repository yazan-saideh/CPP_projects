#include "UsersLoader.h"
#include "RecommendationSystemLoader.h"
#include "SOURCE_PATH.h"

#define EXIT_FAIL_TEST 2;
#define EXIT_SUCCESS_TEST 0;
#define THRESHOLD 0.01

int main(){

	auto rs = RecommendationSystemLoader::create_rs_from_movies(SOURCE_PATH + "TestComparison_6.in_m");
	std::vector<User> user = UsersLoader::create_users(SOURCE_PATH + "TestComparison_6.in_u", std::move(rs));

	if (std::abs(user[0].get_rs_prediction_score_for_movie("TheLastLaugh", 1989, 2) - 4.59) > THRESHOLD ||
		std::abs(user[5].get_rs_prediction_score_for_movie("TheLastLaugh", 1989, 2) - 6.38) > THRESHOLD ||
		std::abs(user[10].get_rs_prediction_score_for_movie("TheLastLaugh", 1989, 2) - 4.98) > THRESHOLD ||
		std::abs(user[15].get_rs_prediction_score_for_movie("TheLastLaugh", 1989, 2) - 4.84) > THRESHOLD ||
//		std::abs(user[20].get_rs_prediction_score_for_movie("TheLastLaugh", 1989, 2) - 7.60) > THRESHOLD ||
		std::abs(user[24].get_rs_prediction_score_for_movie("TheLastLaugh", 1989, 2) - 5.5) > THRESHOLD)
		return EXIT_FAIL_TEST;


	return EXIT_SUCCESS_TEST;
}
