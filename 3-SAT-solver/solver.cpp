#include "solver.hpp"

bool Solver::isSatisfied(std::array<Variable, 3> clause, const std::vector<VarState>& assignment)
{
    for (int i = 0; i < 3; i++)
    {
        if (assignment[clause[i].id] == VarState::True && !clause[i].neg || assignment[clause[i].id] == VarState::False && clause[i].neg)
            return true;
    }

    return false;
}

Output3SAT Solver::solve(const Input3SAT& input)
{
	Output3SAT output;
	output.valuation.resize(input.n);
    output.satisfied = solveAUX(input, output.valuation, 0);

	return output;
}

bool Solver::solveAUX(const Input3SAT& input, std::vector<VarState>& assignment, int i)
{
    if (i == input.clauses.size()) {
        return true;
    }

    if (isSatisfied(input.clauses[i], assignment)) {
        return solveAUX(input, assignment, i + 1);
    }

    std::vector<int> assignedIndicies;

    for (const auto& var : input.clauses[i]) {
        if (assignment[var.id] == VarState::Unassigned) {
            assignedIndicies.push_back(var.id);
            assignment[var.id] = var.neg ? VarState::False : VarState::True;

            if (solveAUX(input, assignment, i + 1)) {
                return true;
            }

            assignment[var.id] = var.neg ? VarState::True : VarState::False;
        }
    }

    for (int idx : assignedIndicies)
        assignment[idx] = VarState::Unassigned;

    return false;
}
