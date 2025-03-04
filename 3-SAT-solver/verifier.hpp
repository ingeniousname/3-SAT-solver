#pragma once
#include "input.hpp"
#include "output.hpp"

class Verifier
{
public:
	bool isValidAnswer(const Input3SAT& input, const Output3SAT& answer);

};