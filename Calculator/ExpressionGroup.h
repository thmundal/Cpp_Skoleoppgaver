#pragma once
#include <string>
#include <vector>

class ExpressionGroup {
private:
public:
	std::vector<ExpressionGroup*> children;
	std::string expression;
	ExpressionGroup* parent = nullptr;
	ExpressionGroup(std::string expression);
	void add_child(ExpressionGroup* child);
	void set_parent(ExpressionGroup* parent);
	void set_expression(std::string expression);
};