#include "input.hpp"
#include <fstream>
#include <iostream>
#include <string>

Input3SAT Input3SAT::readFromFile(const char* filename)
{
	std::ifstream ifs(filename, std::ios::in);
	if (!ifs.good())
	{
		std::cout << "Cannot open file " << filename << "!";
		getchar();
		exit(1);
	}

	Input3SAT input;
	int nClauses;
	ifs >> input.n >> nClauses;

	for (int i = 0; i < nClauses; i++)
	{
		std::string var;
		int idx[3];
		bool neg[3] = { false, false, false };

		for (int i = 0; i < 3; i++)
		{
			ifs >> var;
			if (var[0] == '!')
			{
				neg[i] = true;
				idx[i] = std::stoi(var.substr(1, var.size() - 1));
			}
			else
			{
				idx[i] = std::stoi(var);
			}
		}

		input.clauses.push_back({ Variable{idx[0], neg[0]}, Variable{idx[0], neg[1]}, Variable{idx[2], neg[2]} });
	}

	ifs.close();
	return input;
}
