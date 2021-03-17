#include <iostream>
#include <vector>
#include "../include/Cards.h"

using namespace std;

bool isValid(char choice)
{
	return choice == 'h' || choice == 'l';
}

int main()
{
	const int maxLives = 10;
	int lives = maxLives;
	int round = 1;
	int points = 0;
	bool isGameOver = false;
	char choice;

	vector<Card> deck;
	createDeck(&deck);
	shuffleDeck(&deck);

	while (!isGameOver)
	{
		// Clearing screen
		cout << "\033[2J\033[1;1H";
		//
		cout << "--------------------------------------------" << endl
			 << "                  Round: " << round << endl
			 << "Lives left: " << lives << "/" << maxLives << endl
			 << points << " Points" << endl
			 << deck.size() << " cards left" << endl
			 << endl
			 << "Choose: (H)igh or (L)ow? ";
		cin >> choice;

		if (!isValid(choice))
		{
			cout << "Try again h/l" << endl;
			continue;
		}

		Card card = deck.back();
		deck.pop_back();
		bool isHigh = card.value > 6;
		bool didChooseHigh = choice == 'h';
		bool won = false;
		if ((isHigh && didChooseHigh) || (!isHigh && !didChooseHigh))
		{
			won = true;
		}

		if ((isHigh && !didChooseHigh) || (!isHigh && didChooseHigh))
		{
			won = false;
		}

		if (won)
		{
			points += 10;
			cout << "You guessed right (+10 points)" << endl;
		}
		else
		{
			lives--;
			cout << "You were wrong (lost one life)" << endl;
		}
		printCard(&card);

		round++;
		isGameOver = deck.size() == 0 || lives <= 0;
		cout << "\n\nEnter to continue" << endl;
		std::cin.ignore();
		cin.get();
	}

	cout << endl
		 << endl
		 << "Game over, you scored: " << points << " Points" << endl
		 << " Played: " << round << " rounds" << endl
		 << endl;
}
