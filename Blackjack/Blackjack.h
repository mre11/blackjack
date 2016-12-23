#pragma once

#include <vector>

#include "Player.h"
#include "Deck.h"

class Blackjack
{
public:
	Blackjack();

	void deal();
	bool hit(); // returns true if the Player has not busted	
	bool complete(); // returns true if the Player wins the game

	Card getDealerShowCard() const;
	const std::vector<Card>& getPlayerHand() const;
	int getPlayerScore() const;
	const std::vector<Card>& getDealerHand() const;
	int getDealerScore() const;

private:
	bool hit(Player& player);
	void dealCard(Player& player);
	int calculateScore(const Player& player) const;
	void playDealer();
	void resetHands();
	void resetDeck();

	Player m_dealer;
	Player m_player;
	Deck m_deck;
};

