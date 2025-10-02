#include <iostream>
#include <algorithm>
#include <iomanip>
#include "cube.h"



constexpr Cube::Cube() : cube_arr_{
    {
        { {{1,1,1},{1,1,1},{1,1,1}} },

        { {{2,2,2},{2,2,2},{2,2,2}} },

        { {{3,3,3},{3,3,3},{3,3,3}} },

        { {{4,4,4},{4,4,4},{4,4,4}} },

        { {{5,5,5},{5,5,5},{5,5,5}} },
        
        { {{6,6,6},{6,6,6},{6,6,6}} }
    }
} {}

Cube::Cube(const Cube3x3 &initial_data_) : cube_arr_{initial_data_} {}

Cube::Cube(const int (&c_style_data_)[6][3][3]) {
    std::copy(&c_style_data_[0][0][0], 
              &c_style_data_[0][0][0] + (6 * 3 * 3), 
              &cube_arr_[0][0][0]); 
}

void Cube::displayCube() {
    std::cout << "#========================================================#\n";
    std::cout
    << "    " << "Face1"
    << "    " << "Face2"
    << "    " << "Face3"
    << "    " << "Face4"
    << "    " << "Face5"
    << "    " << "Face6"
    << '\n';

    
    for (int i = 0; i < 3; i++) {
        std::cout << "    ";
        for (int f = 0; f < 6; f++) {
            for (int j = 0; j < 3; j++) {
                std::cout << cube_arr_[f][i][j] << ' ';
            }
            std::cout << "   ";
        }
        std::cout << '\n';
    }

    std::cout << "#========================================================#\n";
}