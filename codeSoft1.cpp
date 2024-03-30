#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    int secretNumber = rand() % 100 + 1; // Generate random number between 1 and 100
    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Guessing Game!\n";
    std::cout << "I have selected a random number between 1 and 100. Try to guess it!\n\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        ++attempts;

        if (guess < secretNumber)
            std::cout << "Too low! Try again.\n";
        else if (guess > secretNumber)
            std::cout << "Too high! Try again.\n";
        else
            std::cout << "Congratulations! You've guessed the correct number (" << secretNumber << ") in " << attempts << " attempts!\n";
    } while (guess != secretNumber);

    return 0;
}
