#include <iostream>
#include <set>
#include <limits>
#include "cube.h"

Cube::Cube() : cube_arr_{
                   {{{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}},

                    {{{2, 2, 2}, {2, 2, 2}, {2, 2, 2}}},

                    {{{3, 3, 3}, {3, 3, 3}, {3, 3, 3}}},

                    {{{4, 4, 4}, {4, 4, 4}, {4, 4, 4}}},

                    {{{5, 5, 5}, {5, 5, 5}, {5, 5, 5}}},

                    {{{6, 6, 6}, {6, 6, 6}, {6, 6, 6}}}}}
{
}

Cube::Cube(const Cube3x3 &initial_data_) : cube_arr_{initial_data_} {}
Cube::Cube(const int (&c_style_data_)[6][3][3])
{
    std::copy(&c_style_data_[0][0][0],
              &c_style_data_[0][0][0] + (6 * 3 * 3),
              &cube_arr_[0][0][0]);
}

void Cube::displayCube()
{
    std::cout << "#========================================================#\n";
    std::cout
        << "    " << "Face1"
        << "    " << "Face2"
        << "    " << "Face3"
        << "    " << "Face4"
        << "    " << "Face5"
        << "    " << "Face6"
        << '\n';

    for (int i = 0; i < 3; i++)
    {
        std::cout << "    ";
        for (int f = 0; f < 6; f++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cout << cube_arr_[f][i][j] << ' ';
            }
            std::cout << "   ";
        }
        std::cout << '\n';
    }

    std::cout << "#========================================================#\n";
}

void Cube::validate_input()
{
    constexpr int targe_count{9};
    std::array<int, 7> global_counts{0, 0, 0, 0, 0, 0, 0};
    std::set<int> unique_centre_value;
    std::string faceNames[6] = {"FRONT", "RIGHT", "BACK", "LEFT", "TOP", "BOTTOM"};

    for (int f = 0; f < 6; f++)
    {
        std::cout << "FACE " << (f + 1) << " (" << faceNames[f] << "):\n";
        for (int r = 0; r < 3; ++r)
        {
            int val1{}, val2{}, val3{};
            bool constraints_failed = false;

            if (!(std::cin >> val1 >> val2 >> val3))
            {
                std::cout << "Error Occurred! Please Enter Valid input (3 numbers, 1-6).\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                --r;
                continue;
            }

            if (std::cin.peek() != '\n' && std::cin.peek() != EOF)
            {
                std::cout << "Invalid format. Please enter *only* three numbers.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                --r;
                continue;
            }

            if (val1 < 1 || val1 > 6 || val2 < 1 || val2 > 6 || val3 < 1 || val3 > 6)
            {
                std::cout << "Invalid range. All numbers must be between 1 and 6.\n";
                // Input succeeded, so no need for clear(), just clean up potential buffer
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                --r;
                continue;
            }

            int temp_val[3] = {val1, val2, val3};
            std::array<int, 7> rollback_count{};

            for (int c{}; c < 3; c++)
            {
                int input_val = temp_val[c];

                if (global_counts[input_val] + rollback_count[input_val] >= 9)
                {
                    std::cout << "!!! Constraint Violated: Number " << input_val
                              << " has been used too many times globally. Re-enter this row.\n";
                    constraints_failed = true;
                    break;
                }

                if (r == 1 && c == 1)
                {

                    if (unique_centre_value.count(input_val))
                    {
                        std::cout << "!!! Constraint Violated: Number " << input_val
                                  << " is already used as a unique center value in another set. Re-enter this row.\n";
                        constraints_failed = true;
                        break;
                    }
                }
                rollback_count[input_val]++;
            }

            if (constraints_failed)
            {
                --r;
                continue;
            }

            if (r == 1)
            {
                unique_centre_value.insert(val2);
            }

            cube_arr_[f][r][0] = val1;
            cube_arr_[f][r][1] = val2;
            cube_arr_[f][r][2] = val3;

            global_counts[val1]++;
            global_counts[val2]++;
            global_counts[val3]++;
        }
    }
}

void Cube::inputCubeState()
{
    std::cout << "#========================================================#\n";
    std::cout << "Enter color for each face (1-6)\n\n";

    validate_input();
}