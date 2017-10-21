#include "Solution.h"
#include "time.h"
#include "stdlib.h"
#include <utility>

Solution::Solution() {
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
		state[i] = '.';
}

Solution Solution::random() {
	Solution s{};
	for (int i = 0; i < SIZE; i++)
		s.state[i] = rand() % SIZE + 1;
	return std::move(s);
}