#include <vector>
#include <iostream>
#include <stdarg.h>

#include "OutputManager.h"

void OutputManager::Print() const {
	std::printf("%s", m_outputLine.c_str());
}

void OutputManager::Reset() {
	m_outputLine.clear();
}

void OutputManager::OutputFormat(const char* format, ...) {
	va_list args;
	va_start(args, format);

	char buf[256];
	std::vsprintf(buf, format, args);
	m_outputLine.append(buf);
}

void OutputManager::OutputNum(const int num) {
	m_outputLine.append(std::to_string(num));
	m_outputLine.append("\n");
}

void OutputManager::OutputNum(const long long num) {
	m_outputLine.append(std::to_string(num));
	m_outputLine.append("\n");
}

void OutputManager::OutputNum(const float num) {
	m_outputLine.append(std::to_string(num));
	m_outputLine.append("\n");
}

void OutputManager::OutputNum(const double num) {
	m_outputLine.append(std::to_string(num));
	m_outputLine.append("\n");
}

void OutputManager::OutputNums(const std::vector<int>& out) {
	repeat(i, out.size()) {
		OutputNum(out[i]);
	}
}

void OutputManager::OutputNums(const std::vector<long long>& out) {
	repeat(i, out.size()) {
		OutputNum(out[i]);
	}
}

void OutputManager::OutputNums(const std::vector<float>& out) {
	repeat(i, out.size()) {
		OutputNum(out[i]);
	}
}

void OutputManager::OutputNums(const std::vector<double>& out) {
	repeat(i, out.size()) {
		OutputNum(out[i]);
	}
}

void OutputManager::OutputBool(const bool result, BoolOutputType type) {
	const char* output;
	switch (type) {
	case YesNo:
		output = result ? "Yes" : "No";
		break;
	case YESNO:
		output = result ? "YES" : "NO";
		break;
	}
	
	OutputFormat("%s", output);
}