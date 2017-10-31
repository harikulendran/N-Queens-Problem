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
	//init
	Board b{};
	int popSize = 1000;
	std::vector<Solution> selecV{};
	srand(time(NULL));
	std::vector<Solution> initPop{};

	//Generate random initial population and apply fitness function
	for (int i = 0; i < popSize; i++) {
		initPop.push_back(Solution::random());
	}

	bool running = true;
	while (running) {
		//Calculate selection Prob and select accordingly
		for (int i = 0; i < initPop.size(); i++) {
			initPop[i].fitness = b.evaluate(initPop[i]);
			initPop[i].selectionProb = ((double)initPop[i].fitness / (double)28) * 100;
			if (rand() % 100 < initPop[i].selectionProb)
				selecV.push_back(initPop[i]);
			if (initPop[i].fitness == ((SIZE * (SIZE - 1)) / 2))
				running = false;
		}

		//Apply cross over
		initPop.clear();
		for (int i = 0; i < selecV.size(); i++)
			for (int j = i + 1; j < selecV.size(); j++) {
				if (selecV.size() > 10000) {
					i = selecV.size();
					j = selecV.size();
				}
				if (rand() % 100 < selecV[j].selectionProb)
					initPop.push_back(Solution::crossOver(selecV[i], selecV[j], rand() % 7 + 1));
			}

		selecV.clear();
		running = (!running) ? false : (initPop.size() > 1);
	}
    return 0;
}