#include "Output.h"

int Output::message(char* msg, ...) {
	char buffer[256];
	va_list args;
	va_start(args, msg);
	vsprintf_s(buffer, msg, args);
	int result = fprintf(stdout, buffer);
	va_end(args);
	return result;
}

int Output::error(char* msg, ...) {
	char buffer[256];
	va_list args;
	va_start(args, msg);
	vsprintf_s(buffer, msg, args);
	int result = fprintf(stderr, buffer);
	va_end(args);
	return result;
}