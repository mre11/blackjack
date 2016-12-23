#include "Blackjack.h"

#include <assert.h>

Blackjack::Blackjack()
{
}

void Blackjack::addPlayer()
{
	m_players.push_back(Player());
}

void Blackjack::deal()
{
	assert(m_players.size() > 0);

	resetHands();
	reshuffleDeck();
	m_activePlayer = m_players.begin();

	for (int i = 0; i < 2; i++)
	{
		for (Player& player : m_players)
			player.dealCard(m_deck.deal());

		m_dealer.dealCard(m_deck.deal());
	}
}

bool Blackjack::hit()
{
	return hit(*m_activePlayer);
}

void Blackjack::stay()
{
	(*m_activePlayer).setScore(calculateScore(*m_activePlayer));

	if (!nextPlayer())
		completeRound();
}

void Blackjack::completeRound()
{
	playDealer();
	m_dealer.setScore(calculateScore(m_dealer));
}

Card Blackjack::getDealerShowCard() const
{
	return m_dealer.getHand()[0];
}

const std::vector<Card>& Blackjack::getDealerHand() const
{
	return m_dealer.getHand();
}

const std::vector<Card>& Blackjack::getActivePlayerHand() const
{
	return (*m_activePlayer).getHand();
}

int Blackjack::getDealerScore() const
{
	return calculateScore(m_dealer);
}

int Blackjack::getActivePlayerScore() const
{
	return calculateScore(*m_activePlayer);
}

bool Blackjack::playerWins(int playerIndex)
{
	auto player = m_players.at(playerIndex);
	return playerWins(player.getScore(), m_dealer.getScore());
}

bool Blackjack::hit(Player& player)
{
	assert(calculateScore(player) < 22);

	player.dealCard(m_deck.deal());
	return calculateScore(player) < 22;
}

bool Blackjack::nextPlayer()
{
	return ++m_activePlayer != m_players.end();
}

void Blackjack::dealCard(Player& player)
{
	player.dealCard(m_deck.deal());
}

int Blackjack::calculateScore(const Player& player) const
{
	int score = 0;
	int aceCount = 0;

	// get the score before aces, and count the aces
	for (auto card : player.getHand())
	{
		if (card.getRank() == 0)
			aceCount++;
		else
			score += card.getPointValue();
	}

	return scoreWithAces(aceCount, score);
}

void Blackjack::playDealer()
{
	while (calculateScore(m_dealer) < 17)
		m_dealer.dealCard(m_deck.deal());
}

void Blackjack::resetHands()
{
	m_dealer.resetHand();

	for (Player& player : m_players)
		player.resetHand();
}

void Blackjack::reshuffleDeck()
{
	m_deck.reset();
}

int Blackjack::scoreWithAces(int numberOfAces, int initialScore) const
{
	int result = initialScore;

	for (int i = 0; i < numberOfAces; i++)
	{
		if (result < 11)
			result += 11;
		else
			result++;
	}

	return result;
}

bool Blackjack::playerWins(int playerScore, int dealerScore) const
{
	return playerScore < 22 && (playerScore == 21 || dealerScore > 21 || playerScore > dealerScore);
}
