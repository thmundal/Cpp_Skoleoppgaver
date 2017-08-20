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
	ExpressionGroup();
	ExpressionGroup* add_child(ExpressionGroup* child);
	void set_parent(ExpressionGroup* parent);
	void set_expression(std::string expression);
	void append_char(char c);
	void append_char(char* c, char* _operator);
	bool has_children();
	double calculate();
};