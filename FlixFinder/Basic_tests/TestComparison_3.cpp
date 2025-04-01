#include "RecommendationSystem.h"
#include <iostream>


int main(){

	RecommendationSystem rs;
	rs.add_movie_to_rs("TheMagnificentAmbersons",2001,{8,6,9,1,1});
	rs.add_movie_to_rs("BrokebackMountain",1966,{5,3,7,4,7});
	std::cout << rs;

	rs.add_movie_to_rs("Muriel",1980,{7,6,8,8,10});
	rs.add_movie_to_rs("TheyWereExpendable",1967,{1,2,8,5,9});
	rs.add_movie_to_rs("Harakiri",1967,{2,6,6,10,5});

	std::cout << rs;
	return 0;
}


