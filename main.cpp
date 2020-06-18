// ComputorV1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include "computor.h";

int main(int argc, char* argv[]) {
	argc = 2; // DEBUG
	const char* argman = "4 * X ^ 0 + 4 * X ^ 1 + 0 * X ^ 2 = 0 * X ^ 0"; // DEBUG
	Equation equation = Equation();
	if (argc == 2)
	{
		if (argc == 2/*std::strlen(argv[1]) > 0*/)
		{
			std::string		eq(argman);

			eq.erase(remove_if(eq.begin(), eq.end(), isspace), eq.end());
			std::replace(eq.begin(), eq.end(), '=', ' ');
			std::vector<std::string> v;
			std::stringstream ss(eq);
			std::string temp;
			while (ss >> temp)
				v.push_back(temp);
			if (v.size() == 2)
			{
				try
				{
					std::vector<Term> left = Computor::ParseEquation(v[0]);
					std::vector<Term> right = Computor::ParseEquation(v[1]);
					for (int i = 0; i < left.size(); i++)
					{
						equation.operator+=(left[i]);
					}
					for (int i = 0; i < right.size(); i++)
					{
						equation.operator-=(right[i]);
					}
					std::cout << equation.toString() << std::endl;
					equation.SolveEquation();
					equation.PrintSolution();
				}
				catch (std::string msg)
				{
					std::cerr << msg << std::endl;
				}
			}
			else
				std::cerr << "Wrong format of equation" << std::endl;
			std::cout << v[0] << std::endl;
		}
		else
			std::cerr << "Empty equation argument" << std::endl;
	}
	else
		std::cerr << "Wrong number of command line arguments" << std::endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
