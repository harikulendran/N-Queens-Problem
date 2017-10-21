#pragma once
#include "Solution.h"
#include <set>

const static int SIZE = 8;

class Solution;

class AttackPair {
public:
	char a, b;

public:
	AttackPair(char ai, char bi);
};

bool eql(const AttackPair &lhs, const AttackPair &rhs) {
	return (lhs.a == rhs.a && lhs.b == rhs.b) || (lhs.a == rhs.b && rhs.a == lhs.b);
}

	//auto eql = [](AttackPair a, AttackPair b) { };

class Board {
	public:
		char state[SIZE][SIZE];
		std::set<AttackPair, bool(*)(const AttackPair&, const AttackPair&)> pairs{ &eql };

	public:
		Board();

	public:
		void reset();
		void setBoard(const Solution& s);
		int evaluate(const Solution& s);
		void evaluatePosition(int x, int y);
		void evaluateDirections(int x, int y, int io, int jo);
};