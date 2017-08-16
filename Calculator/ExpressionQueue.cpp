#include "ExpressionQueue.h"

ExpressionQueue::ExpressionQueue() {
	queue = std::list<Expression*>();
}

void ExpressionQueue::add(Expression* e) {
	queue.push_back(e);
}

void ExpressionQueue::remove(Expression* e) {
	// queue.pop_back(e);
	
}

void ExpressionQueue::sort() {
	/*queue.sort([this](Expression& a, Expression& b) {
		return sort_order.find(a.cOperator) < sort_order.find(b.cOperator);
	});*/
}

double ExpressionQueue::sum() {
	double sum = 0;
	for (Expression* e : queue) {
		sum += (*e).execute();
	}
	return sum;
}