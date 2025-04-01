//
// Created on 2/22/2022.
//

#include "Movie.h"
#define EXIT_SUCCESS_TEST 0
#define EXIT_FAIL_TEST 2

int main()
{
	std::string movie_name = "test";
	int movie_year = 2022;
	const Movie test = Movie(movie_name, movie_year);

	std::cout << "-------------------------" << std::endl;
	std::cout << "Test Movie get_name" << std::endl;
	if (test.get_name() != movie_name)
	{
		std::cerr << "Test Movie get_name failed." << std::endl;
		return EXIT_FAIL_TEST;
	}
	else
	{
		std::cout << "Test Movie get_name succeeded" << std::endl;
	}
	std::cout << "Test Movie get_name done" << std::endl;

	std::cout << "Test Movie get_year" << std::endl;
	if (test.get_year() != movie_year)
	{
		std::cerr << "Test Movie get_year failed." << std::endl;
		return EXIT_FAIL_TEST;
	}
	else
	{
		std::cout << "Test Movie get_year succeeded" << std::endl;
	}
	std::cout << "Test Movie get_year done" << std::endl;
	return EXIT_SUCCESS_TEST;
}
