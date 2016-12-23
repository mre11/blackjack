#include <iostream>

#include "Blackjack.h"

using namespace std;

void runGame()
{
	Blackjack game;

	cout << "Note: enter \"q\" to quit." << endl;
	string input;
	while (true)
	{
		game.deal();

		cout << "Dealer shows " << game.getDealerShowCard() << endl << endl;

		auto playerInitialHand = game.getPlayerHand();
		cout << "Player hand: " << playerInitialHand[0] << " " << playerInitialHand[1] << endl << endl;

		cout << "hit or stay?" << endl;

		string handInput;
		while (cin >> handInput)
		{
			if (handInput == "q")
				return;

			if (handInput == "hit")
			{
				bool result = game.hit();
				cout << "Dealt " << *(game.getPlayerHand().end() - 1) << endl;
				cout << "Player score is now " << game.getPlayerScore() << endl << endl;

				if (!result)
				{
					cout << "You busted! -------------------------------------------------------" << endl;
					break;
				}
			}
			else if (handInput == "stay")
			{
				bool result = game.complete();

				cout << "Dealer hand is ";
				for (auto card : game.getDealerHand())
				{
					cout << card << " ";
				}
				cout << endl;
				cout << "Dealer score is " << game.getDealerScore() << endl << endl;

				if (result)
					cout << "You won! +++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
				else
					cout << "You lost! --------------------------------------------------------" << endl << endl;

				break;
			}
		}
	}
}

int main()
{
	runGame();
}