#include "Solver.h"
#include <math.h>
#include <iostream>

double pi = 3.141592653589793;
Solver::Solver(double x, double error) :Error(error), X(x), Result(x)
{
	//if (fabs(x) > 3037000500.0)
	//{
	//	throw std::invalid_argument("stack overflow: Enter less value");
	//}
	/*bool flag = false;
	if (x < 0)
	{
		x *= -1;
		flag = true;
	}
	if (x > 2 * pi)
	{
		this->X = x - 2 * pi * (int)floor(x / (2 * pi));
	}
	else
		this->X = x;
	if (flag)
		this->Result = -this->X;
	else
		this->Result = this->X;*/
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
	return (this->X + 3) / sin();
}
