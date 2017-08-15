#include <iostream>
#include <functional>
#include <conio.h>
#include <vector>
#include <string>

double doOperation(char op, double a, double b) {
	std::function<double(double, double)> _op;

	//https://stackoverflow.com/a/10424311

	switch (op) {
	case '+': _op = std::plus<float>(); break;
	case '-': _op = std::minus<float>(); break;
	case '*': _op = std::multiplies<float>(); break;
	case '/': _op = std::divides<float>(); break;
	default:
		fprintf(stderr, "Unsupported operator: %c");
		return 0;
	}

	return _op(a, b);
}

double ParseExpression(std::string input) {
	std::vector<char> operators;
	std::vector<double> numbers;
	std::vector<double> tmp_numbers;

	int size = input.length(); // strlen(input);
	int delimiter = 0;

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
			double n = 0;
			for (int i = 0; i < tmp_numbers.size(); i++) {
				n += tmp_numbers[tmp_numbers.size() - 1 - i] * pow(10, i);
			}
			tmp_numbers.clear();
			numbers.push_back(n);
			//std::cout << std::endl << "Legg til tall " << n << std::endl;
			//std::cout << "Input er " << key;

			// Key is not pointing to a number, assume operator
			char cOperator = char(key);
			std::cout << cOperator;
			
			operators.push_back(cOperator);
		}
	}
	// 1+2+3
	double sum = 0;
	char last_operator = '+';
	for (int i = 0; i < numbers.size(); i++) {
		//std::cout << std::endl << " gjør operasjon på " << numbers[i] << std::endl;
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

	std::cout << doOperation(cOperator, dInput_a, dInput_b);
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

	std::cout << "Oppgave 1: Skriv inn et tall, enter, en operator, enter, og et nytt tall" << std::endl;
	Oppgave1();
	std::cout << "Oppgave 2: Skriv et uttrykk pa en linje, eks: 1+2, eller 1 + 2" << std::endl;
	Oppgave2();
	std::cout << "Oppgave 3:" << std::endl;
	std::cin.get();
	Oppgave3();

	std::cout << std::endl << "Press enter to get a beer...";
	std::cin.get();
	return 0;
}