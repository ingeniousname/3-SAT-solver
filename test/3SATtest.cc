#include <gtest/gtest.h>
#include "solver.hpp"

TEST(SATtest, Base3VarTrue) {
	Input3SAT input;
	input.clauses = {
		{ { { 0, true }, { 1, true }, { 2, true } } },
		{ { { 0, false }, { 1, false }, { 2, false } } },
		{ { { 0, false }, { 1, false }, { 2, true } } },
		{ { { 0, false }, { 1, true }, { 2, false } } },
		{ { { 0, true }, { 1, false }, { 2, false } } },
		{ { { 0, false }, { 1, true }, { 2, true } } },
		{ { { 0, true }, { 1, false }, { 2, true } } },
	};
	std::vector<VarState> assignment = { VarState::Unassigned, VarState::Unassigned, VarState::Unassigned };
	EXPECT_TRUE(Solver::solveAUX(input, assignment, 0));
	EXPECT_EQ(assignment[0], VarState::False);
	EXPECT_EQ(assignment[1], VarState::False);
	EXPECT_EQ(assignment[2], VarState::True);
}

TEST(SATtest, Base3VarFalse) {
	Input3SAT input;
	input.clauses = {
		{ { { 0, false }, { 1, false }, { 2, false } } },
		{ { { 0, false }, { 1, false }, { 2, true } } },
		{ { { 0, false }, { 1, true }, { 2, false } } },
		{ { { 0, true }, { 1, false }, { 2, false } } },
		{ { { 0, false }, { 1, true }, { 2, true } } },
		{ { { 0, true }, { 1, false }, { 2, true } } },
		{ { { 0, true }, { 1, true }, { 2, false } } },
		{ { { 0, true }, { 1, true }, { 2, true } } },

	};
	std::vector<VarState> assignment = { VarState::Unassigned, VarState::Unassigned, VarState::Unassigned };
	EXPECT_FALSE(Solver::solveAUX(input, assignment, 0));
}

