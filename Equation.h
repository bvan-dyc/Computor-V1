#pragma once
#include "computor.h";
#include "Term.h";

class Equation
{
public:
	Equation() {};
	Equation(double A, double B, double C);
	Equation(Term termA, Term termB, Term termC);
	~Equation() {};
	void SolveEquation();
	void PrintSolution();
	double A = 0;
	double B = 0;
	double C = 0;
	void operator+=(Term term);
	void operator-=(Term term);
	void operator+=(Equation eqB);
	void operator-=(Equation eqB);
	std::string toString();
private:
	double roots[2] = { 0, 0 };
	bool IsQuadratic();
	void FindQuadraticRoots();
	void FindLinearRoot();
};
