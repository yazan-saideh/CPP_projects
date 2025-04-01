//
// Created by 24565 on 2/22/2022.
//

#include "Movie.h"
#include <iostream>

int main(){

    Movie m1("A",1999);
    Movie m2("B", 2000);
    Movie m3("C",2000);

    std::cout << m1 << m2 << m3 << m1 ;
    return 0;
}