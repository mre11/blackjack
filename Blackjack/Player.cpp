#include "Player.h"

using namespace std;

Player::Player() : m_handScore(0)
{
}

int Player::getScore() const
{
	return m_handScore;
}

void Player::setScore(int score)
{
	m_handScore = score;
}

void Player::dealCard(Card& card)
{
	m_hand.push_back(card);
}

const vector<Card>& Player::getHand() const
{
	return m_hand;
}

void Player::resetHand()
{
	m_handScore = 0;
	m_hand.clear();
}
