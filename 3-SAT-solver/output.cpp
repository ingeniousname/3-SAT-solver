#include "output.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>

void printOutput(const Output3SAT& output)
{
	if (output.satisfied)
	{
		std::cout << "Clauses can be satisfied:\n";
		for (int i = 0; i < output.valuation.size(); i++)
		{
			std::cout << i + 1 << " - " << (output.valuation[i] == VarState::Unassigned ? "any" : output.valuation[i] == VarState::True ? "true" : "false") << "\n";
		}

	}
	else
	{
		std::cout << "Clauses cannot be satisfied.\n";
	}
}

void writeOutputToFile(const Output3SAT& output, const std::string& input_file)
{
	std::string filename = std::filesystem::path(input_file).stem().string() + "_result.txt";
	std::ofstream file = std::ofstream(filename, std::ios::out);
	if (output.satisfied)
	{
		file << "Clauses can be satisfied:\n";
		for (int i = 0; i < output.valuation.size(); i++)
		{
			file << i + 1 << " - " << (output.valuation[i] == VarState::Unassigned ? "any" : output.valuation[i] == VarState::True ? "true" : "false") << "\n";
		}

	}
	else
	{
		file << "Clauses cannot be satisfied.\n";
	}

	file.close();

}
