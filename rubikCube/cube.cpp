#include <iostream>
#include <algorithm>
#include "cube.h"



Cube::Cube() : cube_arr_{
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
    std::cout << "#==============================#" << std::endl;

}