#include "Board.h"
#include "Solution.h"
#include "stdlib.h"
#include <iostream>

AttackPair::AttackPair(char ai, char bi) : a(ai), b(bi) {}

bool AttackPair::operator==(const AttackPair& rhs) {
	return (a == rhs.a && b == rhs.b) || (a == rhs.b && rhs.a == b);
}

bool AttackPair::operator!=(const AttackPair& rhs) {
	return !(*this == rhs);
}

Board::Board() {
	reset();
}

void Board::reset() {
	for (int j = 0; j < SIZE; j++)
		for (int i = 0; i < SIZE; i++)
			state[j][i] = '.';

	for (int j = 0; j < SIZE; j++) {
		sumsLR[j] = 0;
		sumsUD[j] = 0;
		sumsDR[j] = 0;
		sumsDL[j] = 0;
	}
}

void Board::insert(AttackPair& a) {
	for (AttackPair& b : pairs)
		if (a == b)
			return;
	pairs.push_back(std::move(a));
}

void Board::setBoard(const Solution& s) {
	reset();
	for (int i = 0; i < SIZE; i++)
		state[i][(int)s.state[i] - 1] = (char)(i+1);
}

int Board::evaluate(const Solution& s) {
	setBoard(s);
	evaluateDirs();
	int score = countAttack();
	if (score == 0) {
		std::cout << std::endl << "Solution Found: " << std::endl;
		print();
	}
	return (SIZE * (SIZE-1))/2 - score;
}

void Board::evaluateDirs() {
	for (int j = 0; j < SIZE; j++)
		for (int i = 0; i < SIZE; i++)
			if (state[i][j] != '.')
				sumsLR[j]++;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (state[i][j] != '.')
				sumsUD[j]++;
	for (int k = 1; k < SIZE; k++) {
		int j = 0;
		for (int i = k; i >= 0; i--)
			if (state[j++][i] != '.')
				sumsDR[k]++;
	}
	for (int k = 1; k < SIZE; k++) {
		int j = SIZE-1;
		for (int i = k; i >= 0; i--)
			if (state[j--][i] != '.')
				sumsDL[k]++;
	}
}

int Board::countAttack() {
	int out = 0;
	for (int i = 0; i < SIZE; i++) {
		out += comb(sumsLR[i], 2);
		out += comb(sumsUD[i], 2);
		out += comb(sumsDR[i], 2);
		out += comb(sumsDL[i], 2);
	}
	return out;
}

int Board::comb(int n, int k) {
	return (n==k)? 1 : (n <k) ? 0 : fact(n) / (fact(k) * fact(n - k));
}

int Board::fact(int n) {
	return (n == 1) ? n : n * fact(n - 1);
}

void Board::print() {
	for (int j = 0; j < SIZE; j++) {
		for (int i = 0; i < SIZE; i++)
			if (state[i][j] != '.')
				std::cout << (int)state[i][j];
			else
				std::cout << ".";
		std::cout << std::endl;
	}
}