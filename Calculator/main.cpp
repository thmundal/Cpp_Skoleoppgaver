#include <iostream>
#include <functional>
#include <conio.h>
#include <vector>
#include <string>
#include <sstream>

#include "Output.h"
#include "ExpressionGroup.h"

double ParseExpression(std::string in);

bool is_operator(char op) {
	const std::string valid = "+-*/";
	for (char c : valid) {
		if (op == c) return true;
	}
	return false;
}

double doOperation(char op, double a, double b) {
	std::function<double(double, double)> _op;

	const double pi = 3.14159265358979323846;

	//https://stackoverflow.com/a/10424311

	switch (op) {
	case '+': _op = std::plus<double>(); break;
	case '-': _op = std::minus<double>(); break;
	case '*': _op = std::multiplies<double>(); break;
	case '/': 
		_op = std::divides<double>(); 
		// cannot divide by negative numbers....
	break;
	case '^': 
		_op = [](double a, double b) { return pow(a, b); }; 
	break;
	//case '%': return (double)((int)a % (int)b); break;
	//case 's': _op = [](double a, double b) { return sin(b); }; break;
	//case 'c': _op = [](double a, double b) { return cos(b); }; break;
	//case 'p': _op = [pi](double a, double b) { return pi; }; break;
	default:
		Output::error("Unsupported operator: %c %d\n", op, op);
		return 0;
	}

	return _op(a, b);
}

/*
	Added support for decimal points, cred goes to Nils
*/
double make_number(std::vector<double> c, int decimal_point = 0) {
	double n = 0;
	for (int i = 0; i < c.size(); i++) {
		n += c[c.size() - 1 - i] * pow(10, i - decimal_point);
	}
	return n;
}


/*---------------------- PARATHESES GROUPING TEST ------------------------------*/

std::string make_groups(std::string input) {
	std::vector<ExpressionGroup> groups;
	ExpressionGroup _root = ExpressionGroup();
	ExpressionGroup* expression_pointer = nullptr;

	if (expression_pointer == nullptr) {
		expression_pointer = &_root;
	}
	
	for (int i = 0; i < input.length(); i++) {
		char c = input[i];

		if (c == 40) {			// Open paratheses
			ExpressionGroup* child = new ExpressionGroup();
			expression_pointer->add_child(child);
			expression_pointer = child;
		}
		else if (c == 41) {		// Close paratheses
			double sum = ParseExpression(expression_pointer->expression + "=");

			char buffer[10];
			snprintf(buffer, sizeof(buffer), "%g", sum);

			if (expression_pointer->parent != nullptr) {
				expression_pointer->parent->append_char(buffer, "");
				expression_pointer = expression_pointer->parent;
			}
		}
		else {
			expression_pointer->append_char(c);
		}
	}

	return _root.expression;
}
/*---------------------- PARATHESES GROUPING TEST END ------------------------------*/



double ParseExpression(std::string input) {
	std::vector<char> operators;
	std::vector<double> numbers;
	std::vector<double> tmp_numbers;

	int size = input.length();
	bool decimal = false;
	double decimal_sum = 0;
	int decimal_points = 0;
	double sum = 0; // Bug here if the first expression is a multiplicative (0 * x) AND if there are paranteses

	for (int i = 0; i < size; i++) {
		char key = input[i];
		if (key == 32) continue;

		if (key == 46 || key == 44) {
			if (decimal) {
				std::cout << "Received too many decimal points, assuming continuation of number";
			}
			decimal = true;
			continue;
		}
		if (key > 47 && key < 58) // Key is pointing to a number in the ACSII table
		{
			if (decimal) {
				decimal_points++;
			}

			tmp_numbers.push_back(key - 48);

			//std::cout << key - 48;
		}
		else {
			// Fix the numbers
			double n = make_number(tmp_numbers, decimal_points);
			decimal = false;
			decimal_points = 0;

			tmp_numbers.clear();
			numbers.push_back(n);

			// Key is not pointing to a number, assume operator
			char cOperator = char(key);
			//std::cout << cOperator;

			operators.push_back(cOperator);
		}
		
	}

	
	char last_operator = '+';
	for (int i = 0; i<operators.size(); i++) {
		if (operators[i] == '^') {
			double sum = doOperation(operators[i], numbers[i], numbers[i + 1]);
			numbers[i] = 1;
			numbers[i + 1] = sum;

			// Has to ovrrride operators here to keep track of what opertor to use with the result
			operators[i] = last_operator;
		}
		last_operator = operators[i];
	}

	// Do multiplication operators first
	last_operator = '+';
	for(int i=0; i<operators.size(); i++) {
		if (operators[i] == '*' || operators[i] == '/' || operators[i] == '%') {
			double sum = doOperation(operators[i], numbers[i], numbers[i + 1]);
			numbers[i] = 0;
			numbers[i + 1] = sum;
			if (last_operator == '+') {
				operators[i] = '+';
			}
			else
			{
				operators[i] = '-';
			}
		}

		last_operator = operators[i];
	}

	last_operator = '+';
	// Sum all numbers
	for (int i = 0; i < numbers.size(); i++) {
		sum = doOperation(last_operator, sum, numbers[i]);

		if(i < numbers.size() - 1)
			last_operator = operators[i];
	}

	return sum;
}

void Oppgave1() {
	char cOperator;
	double dInput_a, dInput_b;

	std::cin >> dInput_a;
	std::cin >> cOperator;
	std::cin >> dInput_b;

	std::cout << "svaret er " << doOperation(cOperator, dInput_a, dInput_b) << std::endl;
}

void Oppgave2() {
	Oppgave1();
}

void Oppgave3() {
	char cInput;
	std::string sInput = "";

	while ((cInput = std::cin.get()) != '\n') {
		sInput += cInput;
	}

	sInput += "=";

	//std::cout << std::endl << "Evaluer uttrykket: " << sInput << std::endl;
	double sum = ParseExpression(make_groups(std::string(sInput)));

	std::cout << std::endl << "Svaret er " << sInput << sum << std::endl;
}

int main(void)
{

	/*Output::message("Oppgave 1: Skriv inn et tall, enter, en operator, enter, og et nytt tall\n");
	Oppgave1();
	
	Output::message("Oppgave 2: Skriv et uttrykk pa en linje, eks: 1+2, eller 1 + 2\n");
	Oppgave2();

	std::cin.get();
	*/

	// 27 = Escape
	char esc = 0;
	while (esc != 27 && esc != 120) {
		Output::message("Kalkulator: Skriv inn et matematisk uttrykk:\n");
		Oppgave3();
		Output::message("\n\nTrykk enter for å fortsette, skriv inn x for å avslutte\n\n");
		std::cin.get(esc);
	}

	Output::message("Press enter to get a beer...\n");
	std::cin.get();
	return 0;
}