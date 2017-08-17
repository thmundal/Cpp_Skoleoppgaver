#include "ExpressionGroup.h"

ExpressionGroup::ExpressionGroup(std::string _expression) {
	expression = _expression;
}

void ExpressionGroup::add_child(ExpressionGroup* child) {
	children.push_back(child);
}

void ExpressionGroup::set_parent(ExpressionGroup* _parent) {
	parent = _parent;
}

void ExpressionGroup::set_expression(std::string _expression) {
	expression = _expression;
}