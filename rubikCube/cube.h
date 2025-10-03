#ifndef RUBIK
#define RUBIK

#include <array>

class Cube
{

private:
    using Cube3x3 = std::array<std::array<std::array<int, 3>, 3>, 6>;
    Cube3x3 cube_arr_;

    void validate_input();

public:
    Cube();
    Cube(const Cube3x3 &initial_data_);
    Cube(const int (&c_style_data_)[6][3][3]);

    static Cube3x3 get_array_type()
    {
        return {};
    }

    void scramble();

    void face1();
    void face2();
    void face3();
    void face4();
    void face5();
    void face6();

    void displayCube();
    void inputCubeState();

    static constexpr int face{6};
    static constexpr int row{3};
    static constexpr int column{3};
};

#endif