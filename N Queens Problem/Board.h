#pragma once
#include "Solution.h"
#include <vector>

const static int SIZE = 8;

class Solution;

class AttackPair {
public:
	char a, b;

public:
	AttackPair(char ai, char bi);
	bool operator==(const AttackPair& rhs);
	bool operator!=(const AttackPair& rhs);
};

struct AttackPairEql {
	bool operator()(const AttackPair &lhs, const AttackPair &rhs) {
	}
};

class Board {
	public:
		char state[SIZE][SIZE];
		std::vector<AttackPair> pairs{};

	public:
		Board();

	public:
		void insert(AttackPair& a);
		void reset();
		void setBoard(const Solution& s);
		int evaluate(const Solution& s);
		void evaluatePosition(int x, int y);
		void evaluateLR(int x, int y);
		void evaluateUD(int x, int y);
		void evaluateDR(int x, int y);
		void evaluateDL(int x, int y);
		void print();
};