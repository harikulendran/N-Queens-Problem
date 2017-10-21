#include "Board.h"
#include "Solution.h"

AttackPair::AttackPair(char ai, char bi) : a(ai), b(bi) {}

Board::Board() {
	for (int j = 0; j < SIZE; j++)
		for (int i = 0; i < SIZE; i++)
			state[j][i] == '.';
}

void Board::setBoard(const Solution& s) {
	for (int i = 0; i < SIZE; i++)
		state[i][(int)s.state[i]] = (char)i;
}

int Board::evaluate() {

}

int Board::evaluatePosition(int x, int y, int io, int jo) {
	char a = state[x][y];
	for (int j = 1; j < SIZE; j += jo)
		for (int i = 1; i < SIZE; i += io)
			if (state[x + i][y + j] != '.')
				pairs.push_back(std::move(AttackPair{ a,state[x + i][y + j] }));
}