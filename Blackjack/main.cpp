#include <iostream>

#include "Blackjack.h"

using namespace std;

void runGame(int numberOfPlayers)
{
	Blackjack game;

	for (int i = 0; i < numberOfPlayers; i++)
		game.addPlayer();

	cout << "Note: enter \"q\" to quit." << endl;
	string input;
	while (true) // loop for each round
	{
		game.deal();

		cout << "Dealer shows " << game.getDealerShowCard() << endl << endl;

		for (int i = 0; i < numberOfPlayers; i++) // loop for each player
		{
			auto playerInitialHand = game.getActivePlayerHand();
			cout << "==========================================" << endl;
			cout << "Player " << i + 1 << " hand: " << playerInitialHand[0] << " " << playerInitialHand[1] << endl << endl;

			if (game.getActivePlayerScore() == 21)
			{
				cout << "====== BLACKJACK! ======" << endl;
				game.stay(); // maybe need something else here?
				continue;
			}

			cout << "hit, stay, or quit?" << endl;

			string handInput;
			while (cin >> handInput) // player input loop
			{
				if (handInput == "quit")
					return;

				if (handInput == "hit")
				{
					bool result = game.hit();
					cout << "Dealt " << *(game.getActivePlayerHand().end() - 1) << endl;
					cout << "Player score is now " << game.getActivePlayerScore() << endl << endl;

					if (!result)
					{
						cout << "You busted! -------------------------------------------------------" << endl;
						game.stay(); // maybe need something else here?
						break;
					}
					cout << "hit, stay, or quit?" << endl;
				}
				else if (handInput == "stay")
				{
					game.stay();
					break;
				}
			}
		}

		game.completeRound();

		cout << "Dealer hand is ";
		for (auto card : game.getDealerHand())
		{
			cout << card << " ";
		}
		cout << endl;
		cout << "Dealer score is " << game.getDealerScore() << endl << endl;

		// notify players if won
		for (int i = 0; i < numberOfPlayers; i++)
		{
			cout << "Player " << i + 1 << ": ";

			if (game.playerWins(i))
				cout << "You Win!" << endl;
			else
				cout << "You Lose :(" << endl;
		}

		cout << endl << endl;
	}
}

int main()
{
	cout << "How many players (1-7)? ";

	int result;
	while (cin >> result)
	{
		if (result < 1 || result > 7)
		{
			cout << "Not supported" << endl;
			cout << "How many players (1-7)? ";
			continue;
		}
		break;
	}
	runGame(result);
}