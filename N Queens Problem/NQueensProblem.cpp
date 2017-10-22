#include "Solution.h"
#include "Board.h"
#include "time.h"
#include <iostream>
#include <vector>
#include <queue>

struct LessThanFitness {
	bool operator()(const Solution lhs, const Solution rhs) const {
		return lhs.fitness < rhs.fitness;
	}
};

int main() {
	/*Solution s{};
	s.state[0] = (char)3;
	s.state[1] = (char)2;
	s.state[2] = (char)5;
	s.state[3] = (char)4;
	s.state[4] = (char)3;
	s.state[5] = (char)2;
	s.state[6] = (char)1;
	s.state[7] = (char)3;

	Board b{};
	*/
	//std::cout << "Solution Score: " << b.evaluate(s) << std::endl;

	//init
	Board b{};
	int totalFitness = 0;
	int popSize = 100;
	std::priority_queue<Solution, std::vector<Solution>, LessThanFitness> selected{};
	srand(time(NULL));
	std::vector<Solution> initPop{};
	//Generate random initial population and apply fitness function
	for (int i = 0; i < popSize; i++) {
		initPop.push_back(Solution::random());
	}

	while (initPop.size() > 1) {
		//Calculate selection Prob and select accordingly
		for (int i = 0; i < initPop.size(); i++) {
			initPop[i].fitness = b.evaluate(initPop[i]);
			totalFitness += initPop[i].fitness;
			initPop[i].selectionProb = ((double)initPop[i].fitness / (double)28) * 100;
			if (rand() % 100 < initPop[i].selectionProb)
				selected.push(initPop[i]);
		}

		//Apply cross over
		initPop.clear();
		int noSelected = (selected.size() % 2 == 0) ? selected.size() : selected.size() - 1;
		for (int i = 0; i < noSelected / 2; i++) {
			Solution a = selected.top();
			selected.pop();
			Solution b = selected.top();
			selected.pop();

			initPop.push_back(Solution::crossOver(a,b, rand() % 7 + 1));

			int	qq = 0;

		}
		while (selected.size() > 0)
			selected.pop();
	//	std::cout << ".";
	}

	b.evaluate(initPop[0]);
	std::cout << "Score: " << initPop[0].fitness << std::endl;
	b.print();

    return 0;
}