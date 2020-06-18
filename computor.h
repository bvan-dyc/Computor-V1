#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <regex>
#include <float.h>
#include <fstream>
#include "Term.h";
#include "Equation.h";

namespace Computor {
	std::vector<Term> ParseEquation(std::string &equation);
}