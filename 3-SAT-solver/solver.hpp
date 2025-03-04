#pragma once
#include <vector>
#include "input.hpp"
#include "output.hpp"


class Solver {
public:
	Output3SAT solve(const Input3SAT& input);

};