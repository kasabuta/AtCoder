#pragma once

#include <string>
#include <vector>
#include <assert.h>
#include <iostream>
#include <sstream>

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
		m_inputLines = SplitString(input, "\n");
	};

	std::string PopInputLine();

	int GetInputInt();
	long long GetInputLongLong();
	float GetInputFloat();
	double GetInputDouble();
	std::string GetInputString();

	template <typename ...Args>
	int GetInputFormat(const char* format, Args const & ... args);

	template <typename T>
	TwoNums<T> GetInputTwoNums();
	template <typename T>
	std::vector<TwoNums<T>> GetInputTwoNums(int num);

	template <typename T>
	ThreeNums<T> GetInputThreeNums();
	template <typename T>
	std::vector<ThreeNums<T>> GetInputThreeNums(int num);

	template <typename T>
	std::vector<T> GetInputNums(int num);

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

template <typename T>
TwoNums<T> InputManager::GetInputTwoNums() {
	TwoNums<T> input;
	if (m_isCheckMode) {
		auto line = PopInputLine();
		std::istringstream s(line);
		s >> input.first >> input.second;
	} else {
		std::cin >> input.first >> input.second;
	}
	return input;
}

template <typename T>
std::vector<TwoNums<T>> InputManager::GetInputTwoNums(int num) {
	std::vector<TwoNums<T>> input;
	repeat(i, num) {
		auto pair = GetInputTwoNums<T>();
		input.push_back(pair);
	}
	return input;
}

template <typename T>
ThreeNums<T> InputManager::GetInputThreeNums() {
	ThreeNums<T> input;
	if (m_isCheckMode) {
		auto line = PopInputLine();
		std::istringstream s(line);
		s >> input.first >> input.second >> input.third;
	} else {
		std::cin >> input.first >> input.second >> input.third;
	}
	return input;
}

template <typename T>
std::vector<ThreeNums<T>> InputManager::GetInputThreeNums(int num) {
	std::vector<ThreeNums<T>> input;
	repeat(i, num) {
		auto pair = GetInputThreeNums<T>();
		input.push_back(pair);
	}
	return input;
}

template <typename T>
std::vector<T> InputManager::GetInputNums(int num) {
	std::vector<T> input;
	if (m_isCheckMode) {
		while (num > 0) {
			auto line = PopInputLine();
			auto nums = Split<T>(line);
			std::copy(nums.begin(), nums.end(), std::back_inserter(input));
			num -= nums.size();
		}
	} else {
		repeat(i, num) {
			T tmp;
			std::cin >> tmp;
			input.push_back(tmp);
		}
	}
	return input;
}
