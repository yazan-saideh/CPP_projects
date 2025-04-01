#include "RecommendationSystemLoader.h"
#include "UsersLoader.h"
#include "SOURCE_PATH.h"


#define EXIT_FAIL_TEST 2;
#define EXIT_SUCCESS_TEST 0;

int main(){

	auto rs = RecommendationSystemLoader::create_rs_from_movies(SOURCE_PATH + "TestComparison_7.in_m");
	std::vector<User> user = UsersLoader::create_users(SOURCE_PATH + "TestComparison_7.in_u", std::move(rs));

	if (user[0].get_rs_recommendation_by_cf(4)->get_name() != "StrangersonaTrain" ||
            user[5].get_rs_recommendation_by_cf(4)->get_name() != "DaysofBeingWild" ||
            user[10].get_rs_recommendation_by_cf(4)->get_name() != "SweetSmellofSuccess" ||
            user[15].get_rs_recommendation_by_cf(4)->get_year() != 2012 ||
            user[19].get_rs_recommendation_by_cf(4)->get_name() != "BlackOrpheus")
		return EXIT_FAIL_TEST;


	return EXIT_SUCCESS_TEST;
}
