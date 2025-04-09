#include <gtest/gtest.h>
#include "3-SAT-solver/solver.hpp"

TEST(SATtest, BasicAssertions) {
	Input3SAT input;
	input.clauses = {
	{1, 2, 3},
	{-1, -2, -3},
	{1, -2, 3},
	{-1, 2, -3}
	};
	std::vector<VarState> assignment = { UNASSIGNED, UNASSIGNED, UNASSIGNED };
	EXPECT_EQ(Solver::solveAUX(input, assignment, 0), true);
	EXPECT_EQ(assignment[0], TRUE);
	EXPECT_EQ(assignment[1], FALSE);
	EXPECT_EQ(assignment[2], TRUE);
}