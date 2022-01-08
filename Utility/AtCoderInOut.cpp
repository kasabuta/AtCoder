#include "AtCoderInOut.h"

#include <stdarg.h>
#include <stdio.h>

void OutputFormat(std::string* outString, const char* format, ... ) {
	va_list args;
	va_start(args, format);
	std::vprintf(format, args);
	if (outString) {
		char buf[256];
		std::vsprintf(buf, format, args);
		outString->append(buf);
	}
}

void OutputInt(std::string* outString, const int num) {
	

}

void OutputFloat(std::string* outString, const float num);
void OutputLongLong(std::string* outString, const long long num);

void OutputNumsInt(std::string* outString, const std::vector<int> out);
void OutputNumsFloat(std::string* outString, const std::vector<float> out);
void OutputNumsLongLong(std::string* outString, const std::vector<long long> out);