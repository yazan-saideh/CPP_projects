//
// Created by 24565 on 2/24/2022.
//

#include "RecommendationSystem.h"
#include "UsersLoader.h"
#include "SOURCE_PATH.h"

#define EXIT_SUCCESS_TEST 0
#define EXIT_FAIL_TEST 2

int main()
{

    auto rs = std::make_unique<RecommendationSystem>();
    rs->add_movie_to_rs("TheMagnificentAmbersons", 2001, {8, 6, 9, 1, 1});
    rs->add_movie_to_rs("BrokebackMountain", 1966, {5, 3, 7, 4, 7});
    rs->add_movie_to_rs("Muriel", 1980, {7, 6, 8, 8, 10});
    rs->add_movie_to_rs("TheyWereExpendable", 1967, {1, 2, 8, 5, 9});
    rs->add_movie_to_rs("Harakiri", 1967, {2, 6, 6, 10, 5});

    std::vector<User> user = UsersLoader::create_users(SOURCE_PATH + "TestComparison_14.in_u", std::move(rs));
    sp_movie first_prediction = user[0].get_rs_recommendation_by_cf(2);
    user[0].add_movie_to_user("Movie", 1980, {5, 3, 7, 5, 9}, 10);
    sp_movie second_prediction = user[0].get_rs_recommendation_by_cf(2);

    if (first_prediction->get_name() != "TheMagnificentAmbersons" || first_prediction->get_year() != 2001 || second_prediction->get_name() != "TheyWereExpendable" || second_prediction->get_year() != 1967)
    {
        return EXIT_FAIL_TEST;
    }

    return EXIT_SUCCESS_TEST;
}
