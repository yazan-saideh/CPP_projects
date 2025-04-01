//
// Created by 24565 on 2/24/2022.
//

#include "RecommendationSystemLoader.h"
#include "SOURCE_PATH.h"



int main(){

    auto rs = RecommendationSystemLoader::create_rs_from_movies(SOURCE_PATH + "TestComparison_12.in_m");
    std::cout << *rs;

    return 0;

}