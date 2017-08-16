#pragma once
#include "Expression.h"
#include <list>
#include <string>

class ExpressionQueue {
private:
	std::list<Expression*> queue;
	std::string sort_order = "*/+-";
public:
	ExpressionQueue();
	void add(Expression* e);
	void remove(Expression* e);
	int indexOf(Expression* e);
	void sort();
	double sum();
};