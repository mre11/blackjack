#pragma once

#include <iostream>
#include <string>

class Card
{
public:
	Card();
	Card(int suit, int rank);

	int getSuit() const;
	int getRank() const;

	std::string getSuitString() const;
	std::string getRankString() const;

private:
	int m_suit; // hearts, diamonds, clubs, spades
	int m_rank; // ace is 0
};

std::ostream& operator<<(std::ostream& os, const Card& card);
