#include "Expression.h"

Expression::Expression(char _op, double _a, double _b) {
	cOperator = _op;
	a = _a;
	b = _b;
}


double Expression::execute() {
	std::function<double(double, double)> _op;

	//https://stackoverflow.com/a/10424311

	switch (cOperator) {
	case '+': _op = std::plus<float>(); break;
	case '-': _op = std::minus<float>(); break;
	case '*': _op = std::multiplies<float>(); break;
	case '/': _op = std::divides<float>(); break;
	default:
		Output::error("Unsupported operator: %c\n", cOperator);
		return 0;
	}

	return _op(a, b);
}

