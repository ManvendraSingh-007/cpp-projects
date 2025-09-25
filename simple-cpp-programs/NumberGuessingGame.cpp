#include <iostream>
#include <string>
#include <limits>
#include <random>
#include <ctime>


int getIntInput(const std::string& prompt, int defaultValue) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin >> std::ws, input);

    if (!input.empty()) {
        try {
            return std::stoi(input);
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid input. Using default value of " << defaultValue << "." << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Input out of range. Using default value of " << defaultValue << "." << std::endl;
        }
    }
    
    return defaultValue;
}

int main() {
    // Clear any potential hanging newline characters from previous input operations.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Get the min and max values with default options.
    int min = getIntInput("Enter the MIN lower limit (default 1) : ", 1);
    int max = getIntInput("Enter the MAX upper limit (default 100) : ", 100);
    
    // Make sure the min value is not greater than the max value.
    if (min > max) {
        std::cout << "Lower limit cannot be greater than upper limit. Swapping values." << std::endl;
        std::swap(min, max);
    }

    // Get the total number of tries with a default option.
    int totalTries = getIntInput("Constrain Your Guess Limit (default 7) : ", 7);
    if (totalTries <= 0) {
        std::cout << "Guess limit must be greater than 0. Using default value of 7." << std::endl;
        totalTries = 7;
    }

    // Seed the random number generator using the current time.
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number within the specified range.
    int secretNumber = std::rand() % (max - min + 1) + min;
    int guess = 0;
    int tries = 0;

    std::cout << "\nWelcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have a secret number between " << min << " and " << max << "." << std::endl;
    std::cout << "You have " << totalTries << " tries to guess it." << std::endl;

    // Game loop.
    while (tries < totalTries) {
        std::cout << "\nEnter your guess (" << tries + 1 << "/" << totalTries << ") : ";
        std::cin >> guess;

        // Check for invalid input (e.g., a character instead of a number).
        if (std::cin.fail()) {
            std::cout << "Invalid input! Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        tries++;

        if (guess == secretNumber) {
            std::cout << "\nCongratulations! You guessed the number " << secretNumber << " in " << tries << " tries!" << std::endl;
            break;
        } else if (guess > secretNumber) {
            std::cout << "Too high!" << std::endl;
        } else {
            std::cout << "Too low!" << std::endl;
        }
    }

    if (guess != secretNumber) {
        std::cout << "\nSorry, you've run out of tries. The secret number was " << secretNumber << "." << std::endl;
    }

    return 0;
}