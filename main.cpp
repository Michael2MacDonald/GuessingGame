#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
	// Init random seed
	srand(time(NULL));
	int randNum = rand() % 101;

	// Debugging: https://xkcd.com/979/
	//std::cout << randNum << "\n";

	while(1) {

		static int guesses = 20;
		int guess;

		std::cout << "Pick a number between 0 and 100 (inclusive). You have " << guesses << " guesses left.\n";
		std::cout << "Enter your number: ";
		std::cin >> guess;
		guesses--;
		
		// USER WON
		if (guess == randNum) {
			// win message
			std::cout << "You won with " << guesses << " guesses left!\n";
			// ask to play again
			std::cout << "Press type 'y' to play again or 'n' to exit.\n";
			char input;
			std::cin >> input;
			if (input == 'y') {
				randNum = rand() % 101;
				guesses = 20;
			} else { return 0; } // exit
		}
		// USER DID NOT WIN
		else {
			// User has more guesses left
			if (guesses > 0) {
				std::cout << "Incorrect! You have " << guesses << " guesses left.\n";
				if (guess > randNum) { std::cout << "You guessed high!\n"; }
				else if (guess < randNum) { std::cout << "You guessed low!\n"; }
			}
			// User loses
			else {
				std::cout << "Sorry! You lose. The number was " << randNum << ".\n";
				// ask to play again
				std::cout << "Press type 'y' to play again or 'n' to exit.\n";
				char input;
				std::cin >> input;
				if (input == 'y') {
					randNum = rand() % 101;
					guesses = 20;
				} else { return 0; } // exit
			}
		} // if (guess == randNum) else

	} // while loop

	return 0; // exit
}
