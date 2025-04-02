#include "verifier.hpp"

bool Verifier::isValidAnswer(const Input3SAT& input, const Output3SAT& answer)
{
	if (answer.satisfied)
	{
		for (const auto& clause : input.clauses)
		{
			bool value = false;
			for (int i = 0; i < 3; i++)
			{
				value |= (clause[i].neg ? answer.valuation[clause[i].id] == VarState::False : answer.valuation[clause[i].id] == VarState::True);

			}

			if (value == false)
				return false;
		}

	}

	return true;
}
