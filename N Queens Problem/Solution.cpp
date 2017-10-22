#include "Solution.h"
#include "Board.h"
#include "time.h"
#include "stdlib.h"
#include <utility>

Solution::Solution() {
	for (int i = 0; i < SIZE; i++)
		state[i] = '.';
}

Solution Solution::crossOver(Solution& a, Solution& b, int pos) {
	Solution out{};
	for (int i = 0; i < SIZE; i++)
		if (i < pos)
			out.state[i] = a.state[i];
		else
			out.state[i] = b.state[i];
	return out;
}

Solution Solution::random() {
	Solution s{};
	//srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
		s.state[i] = rand() % SIZE + 1;
	return s;
}