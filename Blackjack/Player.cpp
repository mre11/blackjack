#include "Player.h"

using namespace std;

Player::Player()
{
}

void Player::dealCard(Card card)
{
	m_hand.push_back(card);
}

const vector<Card>& Player::getHand() const
{
	return m_hand;
}

void Player::resetHand()
{
	m_hand.clear();
}
