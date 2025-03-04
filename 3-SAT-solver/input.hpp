#pragma once
#include <vector>

struct Variable {
	int id;
	bool neg;
};

struct Input3SAT {
	int n;
	std::vector<std::tuple<Variable, Variable, Variable>> clauses;

	static Input3SAT readFromFile(const char* filename);
};