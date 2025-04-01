cmake_minimum_required(VERSION 3.28)
project(ex51)

set(CMAKE_CXX_STANDARD 20)

add_executable(ex51 Movie.cpp RecommendationSystem.cpp User.cpp UsersLoader.cpp RecommendationSystemLoader.cpp

        TestComparison_3.cpp

)
