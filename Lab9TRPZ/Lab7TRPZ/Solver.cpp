#include "Solver.h"
#include <math.h>
#include <iostream>

double pi = 3.141592653589793;
Solver::Solver(double x, double error) :Error(error), X(x), Result(x)
{
	if (x <= 0 || x > 5)
	{
		throw std::out_of_range("Argument is out of range (0; 5]");
	}
	if (error <= 0 || error >= 1)
	{
		throw std::out_of_range("Error is out of range (0; 5]");
	}
}

double Solver::sin()
{
	double res = this->Result;
	double part = this->Result;
	int i = 1;
	while (true)
	{
		part *= -pow(this->X, 2) / (2 * i * (2 * i + 1));
		if (fabs(part) <= this->Error && i > 15)
			return res;
		res += part;
		i++;
	}
}

double Solver::Solve()
{
	if (fabs(floor(fabs(this->X) / pi) - (fabs(this->X) / pi)) < this->Error)
	{
		throw std::overflow_error("Divide by zero exception");
	}
	return (this->X + 3) / this->sin();
}
