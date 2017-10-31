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
	for (int i = 0; i < SIZE; i++)
		evaluatePosition(i, (int)s.state[i] - 1);
	int score = pairs.size();
	pairs.clear();
	if (score == 0) {
		std::cout << std::endl << "Solution Found: " << std::endl;
		print();
	}
	return (SIZE * (SIZE-1))/2 - score;
}

void Board::evaluatePosition(int x, int y) {
	evaluateLR(x, y);
	evaluateUD(x, y);
	evaluateDR(x, y);
	evaluateDL(x, y);
}

void Board::evaluateLR(int x, int y) {
	char a = state[x][y];
	for (int i = 0; i < SIZE; i++)
		if (i != x && state[i][y] != '.')
			insert(std::move(AttackPair{a, state[i][y]}));
}

void Board::evaluateUD(int x, int y) {
	char a = state[x][y];
	for (int i = 0; i < SIZE; i++)
		if (i != y && state[x][i] != '.')
			insert(std::move(AttackPair{a, state[x][i]}));
}

void Board::evaluateDR(int x, int y) {
	int low = (x < y) ? x : y;
	int nX = x - low;
	int nY = y - low;
	char a = state[x][y];

	for (int i = 0; i < low; i++) {
		if (nX != x && nY != y && state[nX][nY] != '.')
			insert(std::move(AttackPair{ a, state[nX][nY] }));
		nX++;
		nY++;
	}
}

void Board::evaluateDL(int x, int y) {
	int low = (SIZE - 1 - x < y) ? SIZE - 1 - x : y;
	int nX = x + low;
	int nY = y - low;
	char a = state[x][y];

	for (int i = 0; i < low; i++) {
		if (nX != x && nY != y && state[nX][nY] != '.')
			insert(std::move(AttackPair{ a, state[nX][nY] }));
		nX--;
		nY++;
	}
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