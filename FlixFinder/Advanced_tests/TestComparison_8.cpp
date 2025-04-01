#include "RecommendationSystemLoader.h"
#include "UsersLoader.h"
#include "SOURCE_PATH.h"

#define EXIT_SUCCESS_TEST 0
#define EXIT_FAIL_TEST 2

int main()
{
	auto rs = RecommendationSystemLoader::create_rs_from_movies(SOURCE_PATH + "TestComparison_8.in_m");
	std::vector<User> user = UsersLoader::create_users(SOURCE_PATH + "TestComparison_8.in_u", std::move(rs));

	sp_movie first_prediction = user[0].get_rs_recommendation_by_cf(2);
	std::cout << user[3] << std::endl;
    user[0].add_movie_to_user("Movie", 1980, {5, 3, 7, 5, 9}, 10);
	std::cout << user[3] << std::endl;
	sp_movie second_prediction = user[0].get_rs_recommendation_by_cf(2);
	if (first_prediction->get_name() != "TheMagnificentAmbersons" || first_prediction->get_year() != 2001
		|| second_prediction->get_name() != "TheyWereExpendable" || second_prediction->get_year() != 1967)
	{
		return EXIT_FAIL_TEST;
	}

	return EXIT_SUCCESS_TEST;
}
