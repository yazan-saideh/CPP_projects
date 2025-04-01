#include "RecommendationSystem.h"
#define EXIT_SUCCESS_TEST 0
#define EXIT_FAIL_TEST 2

int main()
{
	std::string movie_name = "test";
	int movie_year = 1999;
	RecommendationSystem rs = RecommendationSystem();
	sp_movie add_pointer = rs.add_movie_to_rs(movie_name, movie_year, {1,2,3});
	sp_movie get_pointer = rs.get_movie(movie_name, movie_year);
	std::cout << "-------------------------" << std::endl;
	std::cout << "Test RecommendationSystemadder and getter pointer" << std::endl;
	if (add_pointer.get() != get_pointer.get())
	{
		std::cerr << "Test RecommendationSystemadder and getter pointer failed." << std::endl;
		return EXIT_FAIL_TEST;
	}
	else
	{
		std::cout << "Test RecommendationSystemadder and getter pointer succeeded" << std::endl;
	}
	std::cout << "Test RecommendationSystemadder and getter pointer done" << std::endl;
	return EXIT_SUCCESS_TEST;
}
