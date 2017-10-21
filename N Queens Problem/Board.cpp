#include "Board.h"
#include "Solution.h"

AttackPair::AttackPair(char ai, char bi) : a(ai), b(bi) {}

bool AttackPair::operator==(const AttackPair& rhs) {
	return (a == rhs.a && b == rhs.b) || (a == rhs.b && b == rhs.a);
}

bool AttackPair::operator!=(const AttackPair& rhs) {
	return !(*this == rhs);
}

Board::Board() {
	for (int j = 0; j < SIZE; j++)
		for (int i = 0; i < SIZE; i++)
			state[j][i] == '.';
}

void Board::setBoard(const Solution& s) {
	for (int i = 0; i < SIZE; i++)
		state[i][(int)s.state[i]] = 'Q';
}

int evaluate() {

}

int evaluatePosition(int x, int y, int io, int jo) {
	for (int j = 0; j < SIZE; j+=jo)
		for (int i = 0; i < SIZE; i+=io)
			
}