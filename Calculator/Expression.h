#pragma once

#include <functional>
#include "Output.h"

class Expression {
private:


public:
	double execute();
	double a, b;
	char cOperator;
	Expression(char _op, double a_, double _b);
};