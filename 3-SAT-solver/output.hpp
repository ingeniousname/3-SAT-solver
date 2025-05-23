#pragma once
#include <vector>
#include <string>

enum class VarState { Unassigned, True, False };

struct Output3SAT {
	bool satisfied;
	std::vector<VarState> valuation;
};

void printOutput(const Output3SAT& output);
void writeOutputToFile(const Output3SAT& output, const std::string& input_file);
