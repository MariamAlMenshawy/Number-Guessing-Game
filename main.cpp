#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int DifficultyLevels() {

	int number;
	cout << "There are 3 difficulty levels : \n";
	cout << "1 : Easy (1-50, 10 attempts)\n";
	cout << "2 : Medium (1-100, 7 attempts)\n";
	cout << "3 : Hard (1-500, 5 attempts)\n";

	do {
		cout << "Enter the number of level you want to choose = ";
		
		cin >> number;
		if (number != 1 && number != 2 && number != 3) {
			cout << "That's wrong! choose form 1 to 3 \n";
		}

	} while (number != 1 && number != 2 && number != 3);

	cout << "\n";

	return number;
}

int playGame(int max , int attempts)
{
	
	int computerChoice = rand() % max + 1;

	cout << "I have chosen a number between 1 and " << max << "\n";

	int guessNumber;
	int Attempts = 0;
	for (int i = 1; i <= attempts; i++) {

		Attempts++;

		cout << "Enter your guess number : ";
		cin >> guessNumber;
		if (guessNumber != computerChoice && guessNumber > computerChoice && i != attempts) {
			cout << "Too high! Try again \n";
		}
		else if(guessNumber != computerChoice && guessNumber < computerChoice && i != attempts) {
			cout << "Too low! Try again \n";
		}
		else if (guessNumber != computerChoice && i == attempts) {
			cout << "===== Game Over ===== \n";
			cout << "Out of attempts! The number was " << computerChoice << "\n";
			return INT_MAX;
		}
		else {
			cout << "Correct! You guessed it after " << i << " attempts. \n";
			break;
		}
	}
	return Attempts; 
}

int main()
{

	cout << "\n========== Number Guessing Game ==========\n";
	cout << "\n";
	int bestScore=INT_MAX;
	string play;
	srand(time(0));

	do {

		int levelnumber = DifficultyLevels();
		int score;
		if (levelnumber == 1) {
			score = playGame(50, 10);
			if (score != INT_MAX && bestScore >= score) {
				bestScore = score;
				cout << "New Best Score: " << bestScore << " attempts!\n";
			}
		}
		else if (levelnumber == 2) {
			score = playGame(100, 7);
			if (score != INT_MAX && bestScore >= score) {
				bestScore = score;
				cout << "New Best Score: " << bestScore << " attempts!\n";
			}
		}
		else if (levelnumber == 3) {
			score = playGame(500, 5);
			if (score != INT_MAX && bestScore >= score) {
				bestScore = score;
				cout << "New Best Score: " << bestScore << " attempts!\n";
			}
		}

		
		cout << "\nDo you want to play again? (Yes Or No) ";
		cin >> play;
		cout << "\n";
	} while (play == "Yes" || play == "yes" || play == "YES");
		
	if (bestScore == INT_MAX) {
		cout << "You didn't win any game.\n";
	}
	else {
		cout << "Your best score: " << bestScore << " attempts!\n";
	}
	cout << "Thanks for playing! \n";

	return 0;
}