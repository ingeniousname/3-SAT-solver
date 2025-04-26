// 3-SAT-solver.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "3-SAT-solver/input.hpp"
#include "3-SAT-solver/solver.hpp"
#include "3-SAT-solver/output.hpp"


using namespace std;

int main(int argc, char* argv[])
{
	std::string inputFile = "input/sample.txt";
	if (argc == 2)
		inputFile = std::string(argv[1]);

	auto input = Input3SAT::readFromFile(inputFile.c_str());
	Solver solver;
	auto output = solver.solve(input);
	printOutput(output);
	writeOutputToFile(output, inputFile);

	getchar();
	return 0;
}
