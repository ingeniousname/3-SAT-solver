// 3-SAT-solver.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "input.hpp"
#include "output.hpp"
#include "solver.hpp"


using namespace std;

int main()
{
	auto input = Input3SAT::readFromFile("input/sample.txt");
	Solver solver;
	auto output = solver.solve(input);
	printOutput(output);

	getchar();
	return 0;
}
