#include <gtest/gtest.h>
#include "solver.hpp"

// Test cases to chceck if assignment is correct
TEST(AssignmentTest, Base2Assignment) {
	Input3SAT input;

	// IMPORTANT
	// here true means negation, ~x0 and so on
	input.clauses = {
		{ { { 0, false }, { 1, false }, { 1, false } } },
		{ { { 0, false }, { 1, true }, { 1, true } } },
		{ { { 0, true }, { 1, false }, { 1, false } } },
	};
	std::vector<VarState> assignment = { VarState::Unassigned, VarState::Unassigned};
	EXPECT_TRUE(Solver::solveAUX(input, assignment, 0));
	EXPECT_EQ(assignment[0], VarState::True);
	EXPECT_EQ(assignment[1], VarState::True);
}
TEST(AssignmentTest, Base3Assignment) {
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
	EXPECT_EQ(assignment[0], VarState::True);
	EXPECT_EQ(assignment[1], VarState::True);
	EXPECT_EQ(assignment[2], VarState::False);
}

TEST(AssignmentTest, Base4Assignment) {
	Input3SAT input;

	input.clauses = {
		{ { { 0, false }, { 1, false }, { 2, false } } },
		{ { { 0, false }, { 1, false }, { 2, true } } },
		{ { { 0, false }, { 1, true }, { 2, false } } },
		{ { { 0, false }, { 1, true }, { 3, true } } },
		{ { { 0, false }, { 1, true }, { 3, false } } },
		{ { { 0, true }, { 1, false }, { 2, false } } },
		{ { { 0, true }, { 1, false }, { 2, true}  } },
		{ { { 0, true }, { 1, true }, { 2, false} } },
		{ { { 0, true }, { 1, true }, { 3, true} } }
	};
	std::vector<VarState> assignment = { VarState::Unassigned, VarState::Unassigned, VarState::Unassigned, VarState::Unassigned };
	EXPECT_TRUE(Solver::solveAUX(input, assignment, 0));
	EXPECT_EQ(assignment[0], VarState::True);
	EXPECT_EQ(assignment[1], VarState::True);
	EXPECT_EQ(assignment[2], VarState::True);
	EXPECT_EQ(assignment[3], VarState::False);
}


// Test cases to check if the result is correct
TEST(SATtest, Base2VarTrue) {
	Input3SAT input;

	input.clauses = {
		{ { { 0, false }, { 1, false }, { 1, false } } },
		{ { { 0, false }, { 1, true }, { 1, true } } },
	};
	std::vector<VarState> assignment = { VarState::Unassigned, VarState::Unassigned};
	EXPECT_TRUE(Solver::solveAUX(input, assignment, 0));
}
TEST(SATtest, Base2VarFalse) {
	Input3SAT input;

	input.clauses = {
		{ { { 0, false }, { 1, false }, { 1, false } } },
		{ { { 0, false }, { 1, true }, { 1, true } } },
		{ { { 0, true }, { 1, false }, { 1, false } } },
		{ { { 0, true }, { 0, true }, { 1, true} } }
	};
	std::vector<VarState> assignment = { VarState::Unassigned, VarState::Unassigned};
	EXPECT_FALSE(Solver::solveAUX(input, assignment, 0));
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


TEST(SATtest, Base4VarFalse) {
	Input3SAT input;

	int n = 4;

	input.clauses = {
	{ { { 0, false }, { 1, false }, { 2, false } } },
	{ { { 0, false }, { 1, false }, { 2, true } } },
	{ { { 0, false }, { 1, true }, { 3, false } } },
	{ { { 0, false }, { 1, true }, { 3, true } } },
	{ { { 0, true }, { 2, false }, { 3, false } } },
	{ { { 0, true }, { 2, false }, { 3, true } } },
	{ { { 0, true }, { 2, true }, { 1, false } } },
	{ { { 0, true }, { 2, true }, { 1, true } } },
	};

	std::vector<VarState> assignment;
	for (int i = 0; i < n; i++) {
		assignment.push_back(VarState::Unassigned);
	}
	EXPECT_FALSE(Solver::solveAUX(input, assignment, 0));
}

TEST(SATtest, Base4VarFalse2) {
	Input3SAT input;

	input.clauses = {
		{ { { 0, false }, { 1, false }, { 2, false } } },
		{ { { 0, false }, { 1, false }, { 2, true } } },
		{ { { 0, false }, { 1, true }, { 2, false } } },
		{ { { 0, false }, { 1, true }, { 3, true } } },
		{ { { 0, false }, { 1, true }, { 3, false } } },
		{ { { 0, true }, { 1, false }, { 2, false } } },
		{ { { 0, true }, { 1, false }, { 2, true}  } },
		{ { { 0, true }, { 1, true }, { 2, false} } },
		{ { { 0, true }, { 1, true }, { 3, true} } },
		{ { { 0, true }, { 1, true }, { 3, false} } }
	};
	std::vector<VarState> assignment = { VarState::Unassigned, VarState::Unassigned, VarState::Unassigned, VarState::Unassigned };
	EXPECT_FALSE(Solver::solveAUX(input, assignment, 0));
}
TEST(SATtest, Base4VarTrue) {
	Input3SAT input;

	input.clauses = {
		{ { { 0, false }, { 1, false }, { 2, false } } },
		{ { { 0, false }, { 1, false }, { 2, true } } },
		{ { { 0, false }, { 1, true }, { 2, false } } },
		{ { { 0, false }, { 1, true }, { 3, true } } },
		{ { { 0, false }, { 1, true }, { 3, false } } },
		{ { { 0, true }, { 1, false }, { 2, false } } },
		{ { { 0, true }, { 1, false }, { 2, true}  } },
		{ { { 0, true }, { 1, true }, { 2, false} } },
	};
	std::vector<VarState> assignment = { VarState::Unassigned, VarState::Unassigned, VarState::Unassigned, VarState::Unassigned };
	EXPECT_TRUE(Solver::solveAUX(input, assignment, 0));
}

TEST(SATtest, Base5VarTrue) {
	Input3SAT input;
	int n = 5;
	input.clauses = {
		{ { { 0, false }, { 1, false }, { 2, false } } },
		{ { { 0, false }, { 1, false }, { 3, true } } },
		{ { { 0, false }, { 1, true }, { 2, false } } },
		{ { { 0, true }, { 1, false }, { 2, false } } },
		{ { { 2, false }, { 4, true }, { 1, true } } },
		{ { { 0, true }, { 1, false }, { 2, true } } },
		{ { { 0, true }, { 4, true }, { 3, false } } },
		{ { { 0, true }, { 2, true }, { 4, true } } },

	};
	std::vector<VarState> assignment;
	for (int i = 0; i < 5; i++) {
		assignment.push_back(VarState::Unassigned);
	}
	EXPECT_TRUE(Solver::solveAUX(input, assignment, 0));
}



TEST(SATtest, Base5VarTrue2) {
	Input3SAT input;
	int n = 5;
	input.clauses = {
	{ { { 0, true }, { 3, false }, { 4, false } } },
	{ { { 1, false }, { 2, true }, { 4, false } } },
	{ { { 0, true }, { 1, true }, { 2, false } } },
	};

	std::vector<VarState> assignment;
	for (int i = 0; i < n; i++) {
		assignment.push_back(VarState::Unassigned);
	}
	EXPECT_TRUE(Solver::solveAUX(input, assignment, 0));
}


