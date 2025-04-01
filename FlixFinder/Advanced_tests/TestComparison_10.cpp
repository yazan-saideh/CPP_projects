#include "RecommendationSystemLoader.h"
#include "UsersLoader.h"
#include "SOURCE_PATH.h"

#define EXIT_SUCCESS_TEST 0
#define EXIT_FAIL_TEST 2

int main()
{
	auto rs1 = RecommendationSystemLoader::create_rs_from_movies(SOURCE_PATH + "TestComparison_10.in_m");
	std::vector<User> users1 = UsersLoader::create_users(SOURCE_PATH + "TestComparison_10.in_u", std::move(rs1));
	auto rs2 = RecommendationSystemLoader::create_rs_from_movies(SOURCE_PATH + "TestComparison_10.in_m");
	std::vector<User> users2 = UsersLoader::create_users(SOURCE_PATH + "TestComparison_10.in_u", std::move(rs2));

	users1[49].add_movie_to_user("AAAMovieTestingAddition", 1800, {1, 2, 3, 4, 5}, 5);

	std::cout << users1[0] << std::endl;
	std::cout << users2[1] << std::endl;


	return EXIT_SUCCESS_TEST;
}
