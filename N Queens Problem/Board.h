#pragma once
#include "Solution.h"

const static int SIZE = 4;

class AttackPair {
private:
	char a, b;

public:
	AttackPair(char ai, char bi);
	bool operator==(const AttackPair& rhs);
	bool operator!=(const AttackPair& rhs);
};

class Board {
	public:
		char state[SIZE][SIZE];

	public:
		Board();

	public:
		void setBoard(const Solution& s);
		int evaluate();
};