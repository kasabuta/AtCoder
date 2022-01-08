#pragma once

#include <string>
#include <vector>
#include <assert.h>

#include "Utility.h"

enum BoolOutputType {
	YesNo,
	YESNO,
};

class OutputManager {
public:
	OutputManager()
		: m_isCheckMode(false)
		, m_outputLine() 	{}

	void SetCheckMode(bool isCheckMode) { m_isCheckMode = isCheckMode; }
	
	std::string GetOutput() const {
		auto len = m_outputLine.length();
		auto result = m_outputLine;
		if (result[len - 1] == '\n') {
			result[len - 1] = '\0';
		}
		return result;
	}
	void Print() const;
	void Reset();

	void OutputFormat(const char* format, ...);

	void OutputNum(const int num);
	void OutputNum(const long long num);
	void OutputNum(const float num);
	void OutputNum(const double num);

	void OutputNums(const std::vector<int>& out);
	void OutputNums(const std::vector<long long>& out);
	void OutputNums(const std::vector<float>& out);
	void OutputNums(const std::vector<double>& out);

	void OutputBool(const bool result, BoolOutputType type);

private:
	bool m_isCheckMode;
	std::string m_outputLine;
};
