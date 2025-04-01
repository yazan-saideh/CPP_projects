#include "RecommendationSystemLoader.h"
#include "UsersLoader.h"
#include "SOURCE_PATH.h"

#define EXIT_SUCCESS_TEST 0
#define EXIT_FAIL_TEST 2

int main()
{
	auto rs = RecommendationSystemLoader::create_rs_from_movies(SOURCE_PATH + "TestComparison_9.in_m");
	std::vector<User> user = UsersLoader::create_users(SOURCE_PATH + "TestComparison_9.in_u", std::move(rs));

	std::cout << user[0] << std::endl;
	std::cout << user[1] << std::endl;
	std::cout << user[2] << std::endl;
	std::cout << user[3] << std::endl;

	return EXIT_SUCCESS_TEST;
}