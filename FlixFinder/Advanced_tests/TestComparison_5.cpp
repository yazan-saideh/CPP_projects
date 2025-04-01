#include "SOURCE_PATH.h"
#include "RecommendationSystemLoader.h"
#include "UsersLoader.h"


#define EXIT_FAIL_TEST 2;
#define EXIT_SUCCESS_TEST 0;

int main(){

	auto rs = RecommendationSystemLoader::create_rs_from_movies(SOURCE_PATH + "TestComparison_5.in_m");
	std::vector<User> user = UsersLoader::create_users(SOURCE_PATH + "TestComparison_5.in_u", std::move(rs));

	if (user[0].get_rs_recommendation_by_content()->get_name() != "TheSilence" || user[2].get_rs_recommendation_by_content()->get_name() !=
                                                                               "HighandLow" ||
            user[4].get_rs_recommendation_by_content()->get_name() != "CityLights" ||
            user[6].get_rs_recommendation_by_content()->get_year() != 1992 ||
            user[14].get_rs_recommendation_by_content()->get_name() != "Casablanca")
		return EXIT_FAIL_TEST;


	return EXIT_SUCCESS_TEST;
}
