#include "verifier.hpp"

bool Verifier::isValidAnswer(const Input3SAT& input, const Output3SAT& answer)
{
	if (answer.satisfied)
	{
		for (const auto& [v1, v2, v3] : input.clauses)
		{
			bool value = false;
			value |= (v1.neg ? !answer.valuation[v1.id] : answer.valuation[v1.id]);
			value |= (v2.neg ? !answer.valuation[v2.id] : answer.valuation[v2.id]);
			value |= (v3.neg ? !answer.valuation[v3.id] : answer.valuation[v3.id]);

			if (value == false)
				return false;
		}

	}

	return true;
}
