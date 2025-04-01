//
// Created on 2/22/2022.
//
#include "Movie.h"
#define EXIT_SUCCESS_TEST 0
#define EXIT_FAIL_TEST 2

int main()
{
	std::string movie_name = "a_test";
	int movie_year = 2022;
	const Movie a_new_test = Movie(movie_name, movie_year);
	movie_name = "b_test";
	movie_year = 2022;
	Movie b_test = Movie(movie_name, movie_year);
	movie_name = "test";
	movie_year = 1922;
	Movie a_test = Movie(movie_name, movie_year);

	std::cout << "-------------------------" << std::endl;
	std::cout << "Test Movies with different years" << std::endl;
	if (a_new_test <  a_test)
	{
		std::cerr << "Test Movies with different years failed." << std::endl;
		return EXIT_FAIL_TEST;
	}
	else
	{
		std::cout << "Test Movies with different years succeeded" << std::endl;
	}
	std::cout << "Test Movies with different years done" << std::endl;

	std::cout << "Test Movies with same years" << std::endl;
	if (b_test < a_new_test)
	{
		std::cerr << "Test Movies with same years failed." << std::endl;
		return EXIT_FAIL_TEST;
	}
	else
	{
		std::cout << "Test Movies with same years succeeded" << std::endl;
	}
	std::cout << "Test Movies with same years done" << std::endl;

	std::cout << "Test Movies symmetrically" << std::endl;
	if (a_test < a_test)
	{
		std::cerr << "Test Movies symmetrically failed." << std::endl;
		return EXIT_FAIL_TEST;
	}
	else
	{
		std::cout << "Test Movies symmetrically succeeded" << std::endl;
	}
	std::cout << "Test Movies symmetrically done" << std::endl;
	return EXIT_SUCCESS_TEST;
}

