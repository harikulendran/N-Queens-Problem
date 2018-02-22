#pragma once
#include "Solution.h"
#include <vector>

const static int SIZE = 11;

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
		int sumsLR[SIZE];
		int sumsUD[SIZE];
		int sumsDR[SIZE];
		int sumsDL[SIZE];
		std::vector<AttackPair> pairs{};

	public:
		Board();

	public:
		void insert(AttackPair& a);
		void reset();
		void setBoard(const Solution& s);
		int evaluate(const Solution& s);
		void evaluateDirs();
		int countAttack();
		int comb(int n, int k);
		int fact(int n);
		void print();
};