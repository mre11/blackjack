#pragma once

#include "Player.h"
#include "Deck.h"
#include "Card.h"

#include <vector>
#include <memory>

class Blackjack
{
public:
	Blackjack();

	void addPlayer();
	void deal();
	bool hit(); // returns true if the Player has not busted
	void stay();
	void completeRound(); // returns true if the Player wins the game

	Card getDealerShowCard() const;
	const std::vector<Card>& getDealerHand() const;
	const std::vector<Card>& getActivePlayerHand() const;
	int getDealerScore() const;
	int getActivePlayerScore() const;
	int payout(unsigned int playerIndex) const;

private:
	bool hit(Player& player);
	bool nextPlayer();
	void dealCard(Player& player);
	int calculateScore(const Player& player) const;
	int getPointValue(const Card& card) const;
	void playDealer();
	void resetHands();
	void reshuffleDeck();
	int scoreWithAces(int numberOfAces, int initialScore) const;
	bool playerWins(const Player& player) const;
	bool playerWins(int playerScore, int dealerScore) const;
	int payout(const Player& player) const;

	Deck m_deck;
	Player m_dealer;
	std::vector<Player> m_players;
	std::vector<Player>::iterator m_activePlayer;
};
