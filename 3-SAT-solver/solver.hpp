#pragma once
#include <vector>
#include "input.hpp"
#include "output.hpp"


class Solver {
	static bool isSatisfied(std::array<Variable, 3> clause, const std::vector<VarState>& assignment);
public:
	static Output3SAT solve(const Input3SAT& input);
	static bool solveAUX(const Input3SAT& input, std::vector<VarState>& assignment, int i);

};