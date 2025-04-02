#pragma once
#include <vector>
#include <array>

struct Variable {
	int id;
	bool neg;
};

struct Input3SAT {
	int n;
	std::vector<std::array<Variable, 3>> clauses;

	static Input3SAT readFromFile(const char* filename);
};