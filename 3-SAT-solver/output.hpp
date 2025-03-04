#pragma once
#include <vector>

struct Output3SAT {
	bool satisfied;
	std::vector<bool> valuation;
};

void printOutput(const Output3SAT& output);
