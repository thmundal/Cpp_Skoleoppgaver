#include <iostream>
#include <functional>
#include <conio.h>
#include <vector>
#include <string>

#include "Output.h"

bool is_operator(char op) {
	const std::string valid = "+-*/";
	for (char c : valid) {
		if (op == c) return true;
	}
	return false;
}

double doOperation(char op, double a, double b) {
	std::function<double(double, double)> _op;

	//https://stackoverflow.com/a/10424311

	switch (op) {
	case '+': _op = std::plus<float>(); break;
	case '-': _op = std::minus<float>(); break;
	case '*': _op = std::multiplies<float>(); break;
	case '/': _op = std::divides<float>(); break;
	case '^': _op = [](double a, double b) { return pow(a, b); }; break;
	default:
		Output::error("Unsupported operator: %c %d\n", op, op);
		return 0;
	}

	return _op(a, b);
}

double make_number(std::vector<double> c) {
	double n = 0;
	for (int i = 0; i < c.size(); i++) {
		n += c[c.size() - 1 - i] * pow(10, i);
	}
	return n;
}

double ParseExpression(std::string input) {
	std::vector<char> operators;
	std::vector<double> numbers;
	std::vector<double> tmp_numbers;

	int size = input.length(); // strlen(input);

	for (int i = 0; i < size; i++) {
		char key = input[i];
		if (key == 32) continue;
		if (key > 47 && key < 58) // Key is pointing to a number in the ACSII table
		{
			tmp_numbers.push_back(key - 48);
			
			std::cout << key - 48;
		}
		else {
			// Fix the numbers
			double n = make_number(tmp_numbers);
			
			tmp_numbers.clear();
			numbers.push_back(n);

			// Key is not pointing to a number, assume operator
			char cOperator = char(key);
			std::cout << cOperator;
			
			operators.push_back(cOperator);
		}
	}

	double sum = 0;
	
	std::vector<int> operator_order;
	std::vector<double> numbers_order;

	// Todo: Implement support for exponents
	for (int i = 0; i<operators.size(); i++) {
		if (operators[i] == '^') {
			double sum = doOperation(operators[i], numbers[i], numbers[i + 1]);
			numbers[i] = 1;
			numbers[i + 1] = sum;
			operators[i] = '*';
		}
	}

	// Do multiplication operators first
	for(int i=0; i<operators.size(); i++) {
		if (operators[i] == '*' || operators[i] == '/') {
			double sum = doOperation(operators[i], numbers[i], numbers[i + 1]);
			numbers[i] = 0;
			numbers[i + 1] = sum;
			operators[i] = '+';
		}
	}

	// Sum all numbers
	char last_operator = '+';
	for (int i = 0; i < numbers.size(); i++) {
		sum = doOperation(last_operator, sum, numbers[i]);

		if(i < numbers.size())
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

	std::cout << std::endl << "Evaluer uttrykket: " << sInput << std::endl;
	double sum = ParseExpression(std::string(sInput));
	
	std::cout << std::endl << "Svaret er " << sInput << sum << std::endl;
}

int main(void)
{

	Output::message("Oppgave 1: Skriv inn et tall, enter, en operator, enter, og et nytt tall\n");
	Oppgave1();
	
	Output::message("Oppgave 2: Skriv et uttrykk pa en linje, eks: 1+2, eller 1 + 2\n");
	Oppgave2();

	std::cin.get();

	Output::message("Oppgave 3: Skriv inn et uttrykk som inneholder flere operatorer\n");
	Oppgave3();

	Output::message("Press enter to get a beer...\n");
	std::cin.get();
	return 0;
}