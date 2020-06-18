#include "Equation.h"

Equation::Equation(double A, double B, double C)
{
	this->A = A;
	this->B = B;
	this->C = C;
}

Equation::Equation(Term termA, Term termB, Term termC) {
	A = termA.GetCoefficient();
	B = termB.GetCoefficient();
	C = termC.GetCoefficient();
}

void Equation::SolveEquation() {
	if (IsQuadratic())
	{
		FindQuadraticRoots();
	}
	else
	{
		FindLinearRoot();
	}
}

bool Equation::IsQuadratic() {
	if (A == 0)
		return (false);
	else
		return (true);
}

void Equation::FindQuadraticRoots() {
	double d = -B * B - 4 * A * C;

	if (d == 0)
	{
		roots[0] = roots[1] = -B / (2.0 * A);
		std::cout << "discriminant is zero";
	}
	else if (d > 0)
	{
		std::cout << "discriminant is strictly positive";
		roots[0] = (-B + sqrt(d)) / (2 * A);
		roots[1] = (-B - sqrt(d)) / (2 * A);
	}
	else
	{
		std::cout << "discriminant is strictly negative";
		roots[0] = -B / (2 * A);
		roots[1] = sqrt(-d) / (2 * A);
	}
}

void Equation::FindLinearRoot() {
	if (C == 0)
	{
		if (B != 0)
			std::cout << "solution is zero" << std::endl;
		else
			std::cout << "solution is R" << std::endl;
	}
	else if (B == 0)
	{
		std::cout << "solution is impossible" << std::endl;
	}
	roots[0] = roots[1] = -C / B;
	std::cout << "roots are " + std::to_string(roots[1]) << std::endl;
}

void Equation::operator+=(Term term)
{
	int degree = term.GetDegree();

	if (degree < 0)
	{
		throw "Cannot add term with strictly negative degree to quadratic equation";
		return;
	}
	if (degree > 2)
	{
		throw "Cannot add term with degree above 2 to quadratic equation";
		return;
	}
	double coefficient = term.GetCoefficient();
	if (degree == 2)
		A += coefficient;
	if (degree == 1)
		B += coefficient;
	if (degree == 0)
		C += coefficient;
}

void Equation::operator-=(Term term)
{
	int degree = term.GetDegree();
	double coefficient = term.GetCoefficient();
	if (degree < 0)
	{
		throw "Cannot add term with strictly negative degree to quadratic equation";
		return;
	}
	if (degree > 2)
	{
		throw "Cannot add term with degree above 2 to quadratic equation";
		return;
	}
	if (degree == 2)
		A += coefficient;
	if (degree == 1)
		B += coefficient;
	if (degree == 0)
		C += coefficient;
}

void Equation::operator+=(const Equation eqB)
{
	A += eqB.A;
	B += eqB.B;
	C += eqB.C;
}

void Equation::operator-=(const Equation eqB)
{
	A -= eqB.A;
	B -= eqB.B;
	C -= eqB.C;
}

std::string Equation::toString() {
	std::string result = "";
	if (A > 0)
	{
		result += std::to_string(A) + " * x^2";
		if (B > 0 || C > 0)
		{
			result += " + ";
		}
	}
	if (B > 0)
	{
		result += std::to_string(B) + " * x^1";
		if (C > 0)
		{
			result += " + ";
		}
	}
	if (C > 0)
	{
		result += std::to_string(C) + " * x^0";
	}
	return (result);
}

void Equation::PrintSolution() {
	if (IsQuadratic())
	{
		if (roots[0] == roots[1])
		{
			std::cout << ", the solution is :" << std::endl;
			std::cout << roots[0] << std::endl;
		}
		else {
			std::cout << ", the two solutions are :" << std::endl;
			std::cout << roots[0];
			std::cout << ", ";
			std::cout << roots[1] << std::endl;
		}
	}
	else {
		std::cout << "The solution is :" << std::endl;
		std::cout << roots[0] << std::endl;
	}
}
