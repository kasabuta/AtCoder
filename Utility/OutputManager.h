#pragma once

#include <string>
#include <vector>
#include <assert.h>

#include "Utility.h"

class OutputManager {
public:
	OutputManager()
		: m_isCheckMode(false)
		, m_outputLine() 	{}

	void SetCheckMode(bool isCheckMode) { m_isCheckMode = isCheckMode; }
	
	std::string GetOutput() const { return m_outputLine; }
	void Print() const;

	void OutputFormat(const char* format, ...);

	void OutputInt(const int num);
	void OutputFloat(const float num);
	void OutputLongLong(const long long num);

	void OutputNumsInt(const std::vector<int> out);
	void OutputNumsFloat(const std::vector<float> out);
	void OutputNumsLongLong(const std::vector<long long> out);

private:
	bool m_isCheckMode;
	std::string m_outputLine;
};
