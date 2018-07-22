#pragma once

class Solver
{
public:
	Solver(double x, double error);
	~Solver(){}
	double Result;
	double X;
	double Error;
	double Solve();
private:
	double sin();
};

