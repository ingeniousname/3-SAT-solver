#pragma once
#include <vector>

enum class VarState { Unassigned, True, False };

struct Output3SAT {
	bool satisfied;
	std::vector<VarState> valuation;
};

void printOutput(const Output3SAT& output);
