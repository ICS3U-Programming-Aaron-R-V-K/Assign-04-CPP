// Copyright (2025) Aaron Rivelino All rights reserved.
// Date: May 1, 2025
// Is a dice rolling program that keeps rolling
// until both dice show the same number
// After rolling doubles, asks the user if they want to play again

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <thread>

int main() {
    // Declare variables
    // Get user input as a string
    std::string userInput;

    // Get everything else as an integer
    int die1, die2, rolls, totalRolls = 0, totalGames = 0;

    // Declare this variable to false, to end the whole program
    bool terminateProgram = false;

    // Seed the random number generator
    srand((unsigned)time(NULL));

    // Welcome message
    std::cout << "Welcome to the double dice game!" << std::endl;
    std::cout << "Roll the dice until you get doubles!" << std::endl
              << std::endl;

    // Main game outer loop
    while (true) {
        // Reset the rolls after each game
        rolls = 0;

        // Inner loop for rolling dice until doubles are rolled
        while (true) {
            // Simulate shaking the dice 3 times with after 0.3 seconds
            for (int i = 0; i < 3; i++) {
                std::cout << " Shaking the dice..." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(300));
            }

            // Generate a random number between 1 and 6 for die1 and die2
            die1 = rand() % 6 + 1;
            die2 = rand() % 6 + 1;

            // Increment the number of rolls by 1
            rolls++;

            // Display the current number of rolls, and the random numbers
            std::cout << "Roll " << rolls << ": "
            << die1 << " and " << die2 << std::endl;

            // If dice are doubles, break the loop
            if (die1 == die2) {
                std::cout << "Doubles rolled after "
                << rolls << " attempts!" << std::endl
                          << std::endl;
                break;
            }
        }

        // Update total statistics
        // Add 1 to the total games
        totalGames++;
        // Add the rolls to total rolls before the new game
        totalRolls += rolls;

        // Ask if the user wants to play again
        while (true) {
            std::cout << "Roll again? (yes/y to continue, no/n to stop): ";
            std::cin >> userInput;

            // If yes, it will break and start a new game
            if (userInput == "yes" || userInput == "y") {
                break;
            // If it is no, it will display and calculate the game summary
            // then it will break this loop
            } else if (userInput == "no" || userInput == "n") {
                std::cout << "\nThank you for playing!" << std::endl;

                // Calculate and display stats
                float chanceOfDoubles = static_cast<float> (totalGames)
                / totalRolls * 100;
                float avgRollsPerGame = static_cast<float> (totalRolls)
                / totalGames;

                std::cout << "\nGAME SUMMARY" << std::endl;
                std::cout << "Total games played: " << totalGames << std::endl;
                std::cout << "Total rolls made: " << totalRolls << std::endl;
                std::cout << "Chance of rolling doubles per roll: "
                << chanceOfDoubles << "%" << std::endl;
                std::cout << "Average rolls per game: " << avgRollsPerGame
                << std::endl;

                terminateProgram = true;
                break;
            // If the user enters an Invalid input, it will display this
            } else {
                std::cout << "Invalid input. Please enter 'yes' or 'no'."
                << std::endl;
            }
        }

        // If the user says no, the summary will be displayed.
        // it will stop the entire program
        if (terminateProgram == true) {
            break;
        }
    }

    return 0;
}
