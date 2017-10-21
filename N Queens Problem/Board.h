#pragma once
#include "Solution.h"
#include <set>

const static int SIZE = 4;

class AttackPair {
public:
	char a, b;

public:
	AttackPair(char ai, char bi);
};

auto eql = [](AttackPair a, AttackPair b) {return (a.a == b.a && a.b == b.b) || (a.a == b.b && b.a == a.b); };

class Board {
	public:
		char state[SIZE][SIZE];
		std::set<AttackPair, decltype(eql)> pairs{eql};

	public:
		Board();

	public:
		void setBoard(const Solution& s);
		int evaluate();
		int evaluatePosition(int x, int y, int io, int jo);
};