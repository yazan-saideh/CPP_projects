//
// Created by 24565 on 2/22/2022.
//

#include "RecommendationSystemLoader.h"
#include <memory>
#include "SOURCE_PATH.h"

#define EXIT_FAIL_TEST 2;
#define EXIT_SUCCESS_TEST 0;

int main()
{

	try
	{
		auto rs = RecommendationSystemLoader::create_rs_from_movies(SOURCE_PATH + "TestComparison_15.in_m");
		//				"TestComparison_18.in_m");
		std::cout << *rs << std::endl;
		return EXIT_FAIL_TEST;
	}
	catch (const std::exception &e)
	{
		return EXIT_SUCCESS_TEST;
	}
}