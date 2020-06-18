#pragma once
class Term
{
public:
	Term() {};
	Term(int degree, double coefficient) : _degree(degree), _coefficient(coefficient) {};
	~Term() {};
	void SetCoefficient(double coefficient) { _coefficient = coefficient; }
	double GetCoefficient() { return (_coefficient); }
	int GetDegree() { return (_degree); }

private:
	int _degree = 0;
	double _coefficient = 0;
};
