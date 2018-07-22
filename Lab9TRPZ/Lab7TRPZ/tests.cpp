#include "tests.h"
#include "Solver.h"

TEST(Result, Example1){
	double x = 5.0;
	double e = 0.00001;
	Solver solver(x, e);
	double res = solver.Solve();
	double stRes = (x + 3) / sin(x);
	ASSERT_NEAR(res, stRes, solver.Error);
}

TEST(Result, Example2){
	double x = 2.0;
	double e = 0.00001;
	Solver solver(x, e);
	double res = solver.Solve();
	double stRes = (x + 3) / sin(x);
	ASSERT_NEAR(res, stRes, solver.Error);
}

TEST(ArgBigger, Example1){
	double x = 5.000000000000001;
	ASSERT_THROW(Solver solver(x, 0.00001), std::out_of_range);
}

TEST(ArgBigger, Example2){
	double x = 25.9;
	ASSERT_THROW(Solver solver(x, 0.00001), std::out_of_range);
}

TEST(ArgLess, Example1){
	double x = 0;
	ASSERT_THROW(Solver solver(x, 0.00001), std::out_of_range);
}

TEST(ArgLess, Example2){
	double x = -34.7;
	ASSERT_THROW(Solver solver(x, 0.00001), std::out_of_range);
}


TEST(ErrBigger, Example1){
	double x = 2;
	double e = 1;
	ASSERT_THROW(Solver solver(x, e), std::out_of_range);
}

TEST(ErrBigger, Example2){
	double x = 2;
	double e = 23;
	ASSERT_THROW(Solver solver(x, e), std::out_of_range);
}

TEST(ErrLess, Example1){
	double x = 2;
	double e = 0;
	ASSERT_THROW(Solver solver(x, e), std::out_of_range);
}

TEST(ErrLess, Example2){
	double x = 2;
	double e = -3.8;
	ASSERT_THROW(Solver solver(x, e), std::out_of_range);
}

TEST(ZeroDiv, Example1){
	double x = 0.000000000000001;
	Solver solver(x, 0.00001);
	ASSERT_THROW(solver.Solve(), std::overflow_error);
}

TEST(ZeroDiv, Example2){
	double x = 3.141592653589793;
	double e = 0.000000000000001;
	Solver solver(x, e);
	ASSERT_THROW(solver.Solve(), std::overflow_error);
}