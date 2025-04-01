#include "RecommendationSystem.h"
#define EXIT_SUCCESS_TEST 0
#define EXIT_FAIL_TEST 2

int main()
{
	RecommendationSystem rs1, rs2;
	sp_movie a = rs1.add_movie_to_rs("TheMagnificentAmbersons", 2001, {8, 6, 9, 1});
	sp_movie b = rs1.add_movie_to_rs("BrokebackMountain", 1966, {5, 3, 7, 4});
	sp_movie c = rs2.add_movie_to_rs("TheAvengers", 2012, {5, 3, 7, 5});

	std::cout << "-------------------------" << std::endl;
	std::cout << "Test RecommendationSystemadd movie for the movie" << std::endl;
	sp_movie d = rs1.add_movie_to_rs("Muriel", 1980, {7, 6, 8, 8});

	if (rs2.get_movie("TheMagnificentAmbersons", 2001).get() != nullptr ||
	        rs1.get_movie("TheMagnificentAmbersons", 2001).get() != a.get() ||
			rs1.get_movie("TheAvengers", 2012).get() != nullptr ||
			rs2.get_movie("TheAvengers", 2012).get() != c.get())
	{
		std::cerr << "Test RecommendationSystemadd movie for the movie failed." << std::endl;
		return EXIT_FAIL_TEST;
	}
	else
	{
		std::cout << "Test RecommendationSystemadd movie for the movie succeeded" << std::endl;
	}
	std::cout << "Test RecommendationSystemadd movie for the movie done" << std::endl;

	return EXIT_SUCCESS_TEST;
}
