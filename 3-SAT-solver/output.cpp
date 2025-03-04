#include "output.hpp"
#include <iostream>

void printOutput(const Output3SAT& output)
{
	if (output.satisfied)
	{
		std::cout << "Clauses can be satisfied:\n";
		for (int i = 0; i < output.valuation.size(); i++)
		{
			std::cout << i << " - " << (output.valuation[i] ? "true" : "false") << "\n";
		}

	}
	else
	{
		std::cout << "Clauses cannot be satisfied.\n";
	}
}
