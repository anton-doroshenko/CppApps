#pragma once

#include<string>
#include<iostream>

class Error
{
public:
	int type;
	std::string *str;

	Error() {}
	Error(int t, std::string *str) : type(t), str(str) {}

	~Error() {}

	void input(std::string*);

	void valOfCandidates();

	void valOfWorkers();

	void err(std::string*);
};

