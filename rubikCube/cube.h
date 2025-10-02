#ifndef RUBIK
#define RUBIK

#include <array>

class Cube {

private:
    using Cube3x3 = std::array<std::array<std::array<int, 3>, 3>, 6>;
    Cube3x3 cube_arr_;

public:

    Cube();
    Cube(const Cube3x3 &initial_data_);
    Cube(const int (&c_style_data_)[6][3][3]);

    static Cube3x3 get_array_type() {
        return {};
    }

    void displayCube();

   
};

#endif