#include "ExpressionGroup.h"

ExpressionGroup::ExpressionGroup(std::string _expression) {
	expression = _expression;
}

ExpressionGroup::ExpressionGroup() {
	expression = "";
}

ExpressionGroup* ExpressionGroup::add_child(ExpressionGroup* child) {
	children.push_back(child);
	child->set_parent(this);
	return child;
}

void ExpressionGroup::set_parent(ExpressionGroup* _parent) {
	parent = _parent;
}

void ExpressionGroup::set_expression(std::string _expression) {
	expression = _expression;
}

void ExpressionGroup::append_char(char c) {
	//expression = expression.append(c);
	expression += c;
}

void ExpressionGroup::append_char(char* c, char* _operator) {
	expression = expression.append(_operator);
	expression = expression.append(c);
}

bool ExpressionGroup::has_children() {
	return children.size() > 0;
}

double ExpressionGroup::calculate() {

	return 0;
}

ExpressionGroup::~ExpressionGroup() {
	for (int i = 0; i < children.size(); i++) {
		delete children[i];
	}
}