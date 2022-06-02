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

// 1024bite‚Ü‚Å‚µ‚©‘Î‰‚µ‚Ä‚¢‚È‚¢‚Ì‚Å’ˆÓ
void OutputManager::OutputFormat(const char* format, ...) {
	va_list args;
	va_start(args, format);

	char buf[1024];
	std::vsprintf(buf, format, args);
	m_outputLine.append(buf);
}

void OutputManager::OutputString(const char* str) {
	m_outputLine.append(str);
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
	OutputFormat("%.12f", num);
	m_outputLine.append("\n");
}

void OutputManager::OutputNums(const std::vector<int>& out) {
	for (auto itr : out) {
		OutputNum(itr);
	}
}

void OutputManager::OutputNums(const std::vector<long long>& out) {
	for (auto itr : out) {
		OutputNum(itr);
	}
}

void OutputManager::OutputNums(const std::vector<float>& out) {
	for (auto itr : out) {
		OutputNum(itr);
	}
}

void OutputManager::OutputNums(const std::vector<double>& out) {
	for (auto itr : out) {
		OutputNum(itr);
	}
}

void OutputManager::OutputNumsInLine(const std::vector<int>& out) {
	std::string line;
	int size = out.size();
	repeat(i, size) {
		line.append(std::to_string(out[i]));
		if(i != size - 1) line.append(" ");
	}
	m_outputLine.append(line);
	m_outputLine.append("\n");
}
void OutputManager::OutputNumsInLine(const std::vector<long long>& out) {
	std::string line;
	int size = out.size();
	repeat(i, size) {
		line.append(std::to_string(out[i]));
		if(i != size - 1) line.append(" ");
	}
	m_outputLine.append(line);
	m_outputLine.append("\n");
}
void OutputManager::OutputNumsInLine(const std::vector<float>& out) {
	std::string line;
	int size = out.size();
	repeat(i, size) {
		line.append(std::to_string(out[i]));
		if(i != size - 1) line.append(" ");
	}
	m_outputLine.append(line);
	m_outputLine.append("\n");
}
void OutputManager::OutputNumsInLine(const std::vector<double>& out) {
	std::string line;
	int size = out.size();
	repeat(i, size) {
		line.append(std::to_string(out[i]));
		if(i != size - 1) line.append(" ");
	}
	m_outputLine.append(line);
	m_outputLine.append("\n");
}

void OutputManager::OutputMatrix(const Matrix<int>& out) {
	for (auto itr : out) {
		OutputNumsInLine(itr);
	}
}
void OutputManager::OutputMatrix(const Matrix<long long>& out) {
	for (auto itr : out) {
		OutputNumsInLine(itr);
	}
}
void OutputManager::OutputMatrix(const Matrix<float>& out) {
	for (auto itr : out) {
		OutputNumsInLine(itr);
	}
}
void OutputManager::OutputMatrix(const Matrix<double>& out) {
	for (auto itr : out) {
		OutputNumsInLine(itr);
	}
}

void OutputManager::OutputBool(const bool result, int type) {
	const char* output = "";
	switch (type) {
	case YesNo:
		output = result ? "Yes" : "No";
		break;
	case YESNO:
		output = result ? "YES" : "NO";
		break;
	}
	
	OutputFormat("%s\n", output);
}