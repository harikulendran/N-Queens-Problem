#include "Board.h"
#include "Solution.h"

AttackPair::AttackPair(char ai, char bi) : a(ai), b(bi) {}

Board::Board() {
	reset();
}

void Board::reset() {
	for (int j = 0; j < SIZE; j++)
		for (int i = 0; i < SIZE; i++)
			state[j][i] = '.';
}

void Board::setBoard(const Solution& s) {
	reset();
	for (int i = 0; i < SIZE; i++)
		state[i][(int)s.state[i]] = (char)i;
}

int Board::evaluate(const Solution& s) {
	setBoard(s);
	for (int i = 0; i < SIZE; i++)
		evaluatePosition(i, (int)s.state[i]);
	int score = pairs.size();
	pairs.clear();
	return score;
}

void Board::evaluatePosition(int x, int y) {
	evaluateDirections(x, y, 1, 0);
	evaluateDirections(x, y, 0, 1);
	evaluateDirections(x, y, 1, 1);
}

void Board::evaluateDirections(int x, int y, int io, int jo) {
	char a = state[x][y];
	for (int j = 1; y+j < SIZE; j += jo)
		for (int i = 1; x+i < SIZE; i += io)
			if (state[x + i][y + j] != '.')
				pairs.insert(std::move(AttackPair{ a,state[x + i][y + j] }));
	for (int j = -1; y+j >= 0; j -= jo)
		for (int i = -1; x+i >= 0; i -= io)
			if (state[x + i][y + j] != '.')
				pairs.insert(std::move(AttackPair{ a,state[x + i][y + j] }));
}