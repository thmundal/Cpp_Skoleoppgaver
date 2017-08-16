#pragma once
#include <iostream>
#include <stdarg.h>

class Output {
public:
	static int message(char* msg, ...);
	static int error(char* msg, ...);
};