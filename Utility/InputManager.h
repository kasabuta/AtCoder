#pragma once

#include <string>
#include <vector>
#include <assert.h>

#include "Utility.h"

const int MAX_LINE_LENGTH = 1024;

class InputManager {
public:
	InputManager()
		: m_isCheckMode(false)
		, m_inputLines() 	{}

	void SetCheckMode(bool isCheckMode) { m_isCheckMode = isCheckMode; }

	void SetupInputCase(const char* inputCase) {
		m_inputLines.clear();

		std::string input = inputCase;
		m_inputLines = Split(input, "\n");
	};

	int GetInputInt();
	float GetInputFloat();
	long long GetInputLongLong();
	std::string GetInputString();

	template <typename ...Args>
	int GetInputFormat(const char* format, Args const & ... args);

	void GetInputNums2(int* in1, int* in2);
	void GetInputNums2(float* in1, float* in2);
	void GetInputNums2(long long* in1, long long* in2);

	void GetInputNums3(int* in1, int* in2, int* in3);
	void GetInputNums3(float* in1, float* in2, float* in3);
	void GetInputNums3(long long* in1, long long* in2, long long* in3);

	void GetInputNums(std::vector<int>* in, int num);
	void GetInputNums(std::vector<float>* in, int num);
	void GetInputNums(std::vector<long long>* in, int num);

private:
	bool m_isCheckMode;
	std::vector<std::string> m_inputLines;
};

/* 解答用の出力とテストケースを使ったチェックを切り替えるための入力関数 */
template <typename ...Args>
int InputManager::GetInputFormat(const char* format, Args const & ... args) {
	if (m_isCheckMode) {
		if (!m_inputLines.empty()) {
			auto inputCase = m_inputLines.front();
			m_inputLines.erase(m_inputLines.begin());
			return std::sscanf(inputCase.c_str(), format, args...);
		} else {
			assert("reference invalid index in \"m_inputLines\".");
		}
	} else {
		return std::scanf(format, args...);
	}
	return EOF;
}