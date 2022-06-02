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
		if (len != 0 && result[len - 1] == '\n') {
			result[len - 1] = '\0';
		}
		return result;
	}
	void Print() const;
	void Reset();

	void OutputFormat(const char* format, ...);

	void OutputString(const char* str);

	void OutputNum(const int num);
	void OutputNum(const long long num);
	void OutputNum(const float num);
	void OutputNum(const double num);

	void OutputNums(const std::vector<int>& out);
	void OutputNums(const std::vector<long long>& out);
	void OutputNums(const std::vector<float>& out);
	void OutputNums(const std::vector<double>& out);

	void OutputNumsInLine(const std::vector<int>& out);
	void OutputNumsInLine(const std::vector<long long>& out);
	void OutputNumsInLine(const std::vector<float>& out);
	void OutputNumsInLine(const std::vector<double>& out);

	void OutputMatrix(const Matrix<int>& mat);
	void OutputMatrix(const Matrix<long long>& mat);
	void OutputMatrix(const Matrix<float>& mat);
	void OutputMatrix(const Matrix<double>& mat);

	void OutputBool(const bool result, int type);

private:
	bool m_isCheckMode;
	std::string m_outputLine;
};
