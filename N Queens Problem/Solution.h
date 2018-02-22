#pragma once

class Solution {
	public:
		char state[11];
		int fitness = 0;
		double selectionProb = 0;
	public:
		Solution();
	public:
		static Solution crossOver(Solution& a, Solution& b, int pos);
		static Solution random();
};