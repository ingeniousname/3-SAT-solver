#include "solver.hpp"

Output3SAT Solver::solve(const Input3SAT& input)
{
	Output3SAT output;
	output.satisfied = true;
	output.valuation.resize(input.n);

	return output;
}
