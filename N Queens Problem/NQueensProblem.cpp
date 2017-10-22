#include "Solution.h"
#include "Board.h"
#include <iostream>

int main() {
	Solution s{};
	s.state[0] = (char)3;
	s.state[1] = (char)2;
	s.state[2] = (char)5;
	s.state[3] = (char)4;
	s.state[4] = (char)3;
	s.state[5] = (char)2;
	s.state[6] = (char)1;
	s.state[7] = (char)3;

	Board b{};

	std::cout << "Solution Score: " << b.evaluate(s) << std::endl;
    return 0;
}