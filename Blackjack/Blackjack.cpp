#include "Blackjack.h"

#include <assert.h>

Blackjack::Blackjack()
{
}

void Blackjack::deal()
{
	resetHands();

	if (m_deck.count() < 15)
		resetDeck(); // reshuffle

	m_player.dealCard(m_deck.deal());
	m_dealer.dealCard(m_deck.deal());
	m_player.dealCard(m_deck.deal());
	m_dealer.dealCard(m_deck.deal());
}

bool Blackjack::hit()
{
	return hit(m_player);
}

bool Blackjack::hit(Player& player)
{
	assert(calculateScore(player) < 22);

	player.dealCard(m_deck.deal());
	return calculateScore(player) < 22;
}

bool Blackjack::complete()
{
	playDealer();

	int playerScore = calculateScore(m_player);
	int dealerScore = calculateScore(m_dealer);

	if (playerScore == 21 || dealerScore > 21 || playerScore > dealerScore)
		return true;

	return false;
}

Card Blackjack::getDealerShowCard() const
{
	return m_dealer.getHand()[0];
}

const std::vector<Card>& Blackjack::getPlayerHand() const
{
	return m_player.getHand();
}

int Blackjack::getPlayerScore() const
{
	return calculateScore(m_player);
}

const std::vector<Card>& Blackjack::getDealerHand() const
{
	return m_dealer.getHand();
}

int Blackjack::getDealerScore() const
{
	return calculateScore(m_dealer);
}

void Blackjack::dealCard(Player& player)
{
	player.dealCard(m_deck.deal());
}

int Blackjack::calculateScore(const Player& player) const
{
	int score = 0;
	for (auto card : player.getHand())
	{
		score += card.getPointValue();
	}

	return score;
}

void Blackjack::playDealer()
{
	while (calculateScore(m_dealer) < 17)
		m_dealer.dealCard(m_deck.deal());
}

void Blackjack::resetHands()
{
	m_dealer.resetHand();
	m_player.resetHand();
}

void Blackjack::resetDeck()
{
	m_deck.reset();
}
