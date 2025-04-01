//
// Created by 24565 on 2/24/2022.
//

#include "UsersLoader.h"
#include "RecommendationSystem.h"
#include "SOURCE_PATH.h"

int main(){
    auto rs = std::make_unique<RecommendationSystem>();
    rs->add_movie_to_rs("TheMagnificentAmbersons",2001,{8,6,9,1,1});
    rs->add_movie_to_rs("BrokebackMountain",1966,{5,3,7,4,7});
    rs->add_movie_to_rs("Muriel",1980,{7,6,8,8,10});
    rs->add_movie_to_rs("TheyWereExpendable",1967,{1,2,8,5,9});
    rs->add_movie_to_rs("Harakiri",1967,{2,6,6,10,5});

    std::vector<User> user = UsersLoader::create_users(SOURCE_PATH + "TestComparison_13.in_u", std::move(rs));
    std::cout << user[3];

    return 0;
}
