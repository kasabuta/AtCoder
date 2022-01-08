#include <vector>
#include <iostream>
#include <stdarg.h>

#include "OutputManager.h"

void OutputManager::Print() const {
	std::printf("%s", m_outputLine.c_str());
}

void OutputManager::OutputFormat(const char* format, ...) {
	va_list args;
	va_start(args, format);

	char buf[256];
	std::vsprintf(buf, format, args);
	m_outputLine.append(buf);
}

void OutputManager::OutputInt(const int num) {
	m_outputLine.append(std::to_string(num));
	m_outputLine.append("\n");
}

void OutputManager::OutputFloat(const float num) {
	m_outputLine.append(std::to_string(num));
	m_outputLine.append("\n");
}

void OutputManager::OutputLongLong(const long long num) {
	m_outputLine.append(std::to_string(num));
	m_outputLine.append("\n");
}

void OutputManager::OutputNumsInt(const std::vector<int> out) {
	repeat(i, out.size()) {
		OutputInt(out[i]);
	}
}

void OutputManager::OutputNumsFloat(const std::vector<float> out) {
	repeat(i, out.size()) {
		OutputFloat(out[i]);
	}
}

void OutputManager::OutputNumsLongLong(const std::vector<long long> out) {
	repeat(i, out.size()) {
		OutputLongLong(out[i]);
	}
}