//
// Created by 24565 on 2/22/2022.
//

#include "RecommendationSystem.h"
#include "RecommendationSystemLoader.h"
#include "UsersLoader.h"
#include <memory>
#include "SOURCE_PATH.h"

#define EXIT_FAIL_TEST 2;
#define EXIT_SUCCESS_TEST 0;

int main()
{

	try
	{
		//        auto rs = std::make_unique<RecommendationSystem>();
		//        rs->add_movie_to_rs("TheMagnificentAmbersons",2001,{8,6,9,1,1});
		//        rs->add_movie_to_rs("BrokebackMountain",1966,{5,3,7,4,7});
		//        rs->add_movie_to_rs("Muriel",1980,{7,6,8,8,10});
		//        rs->add_movie_to_rs("TheyWereExpendable",1967,{1,2,8,5,9});
		//        rs->add_movie_to_rs("Harakiri",1967,{2,6,6,10,5});
		auto rs = RecommendationSystemLoader::create_rs_from_movies(SOURCE_PATH + "TestComparison_16.in_m");
		auto users = UsersLoader::create_users(SOURCE_PATH + "TestComparison_16.in_u", std::move(rs));
		//				"TestComparison_18.in_m");
		return EXIT_FAIL_TEST;
	}
	catch (const std::exception &e)
	{
		return EXIT_SUCCESS_TEST;
	}
}
