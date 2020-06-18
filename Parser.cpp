# include "computor.h";
namespace Computor {

	std::vector<Term> ParseEquation(std::string& equation) {
		std::vector<Term>		terms;
		std::smatch				match;
		size_t		counter = 0;

		if (std::regex_match(equation, match, std::regex("[+-]?[0-9]+([.][0-9]+)?[*][X][^][0]"
			"([+-][0-9]+([.][0-9]+)?[*][X][^][1])?"
			"([+-][0-9]+([.][0-9]+)?[*][X][^][2])?")))
		{
			std::regex words_regex("[+-]?[0-9]+([.][0-9]+)?");
			auto start = std::sregex_iterator(equation.begin(), equation.end(), words_regex);
			auto end = std::sregex_iterator();
			for (std::sregex_iterator i = start; i != end; ++i, ++counter)
			{
				if (counter == 0 || (counter % 2) == 0)
				{
					double num = stod((*i).str());
					if (num == -DBL_MAX)
						throw std::string("Coefficient is too large");
					terms.push_back(Term(counter / 2, num));
				}
			}
		}
		else
			throw std::string("Undefined character");
		return (terms);
	}

	bool StringIsValid(Equation equation) {

		if (std::regex_match(equation, match, std::regex("[+-]?[0-9]+([.][0-9]+)?[*][X][^][0]"
			"([+-][0-9]+([.][0-9]+)?[*][X][^][1])?"
			"([+-][0-9]+([.][0-9]+)?[*][X][^][2])?")))
			return true;
		else
			return false;
	}
}