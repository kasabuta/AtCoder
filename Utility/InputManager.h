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

	int GetInt();
	long long GetLongLong();
	float GetFloat();
	double GetDouble();
	std::string GetString();
	std::vector<std::string> GetStrings(int num);

	template <typename T>
	std::vector<T> GetNumsWithCond(int cond1, int num1, int cond2, int num2);

	template <typename ...Args>
	int GetFormat(const char* format, Args const & ... args);

	template <typename T>
	TwoNums<T> GetTwoNums();
	template <typename T>
	std::vector<TwoNums<T>> GetTwoNums(int num);
	template <typename T>
	std::vector<TwoNums<T>> GetTwoNumsAsIndex(int num);

	template <typename T>
	ThreeNums<T> GetThreeNums();
	template <typename T>
	std::vector<ThreeNums<T>> GetThreeNums(int num);

	std::vector<Edge> GetPathWeight(int num);

	template <typename T>
	std::vector<T> GetNums(int num);
	template <typename T>
	std::vector<T> GetNumsAsIndex(int num);

	template <typename T>
	Matrix<T> GetMatrix(int h, int w);
	template <typename T>
	Matrix<T> GetMatrix(TwoNums<int> hw);
private:
	bool m_isCheckMode;
	std::vector<std::string> m_inputLines;
};


template <typename T>
std::vector<T> InputManager::GetNumsWithCond(int cond1, int num1, int cond2, int num2) {
	//@todo
}

/* 解答用の出力とテストケースを使ったチェックを切り替えるための入力関数 */
template <typename ...Args>
int InputManager::GetFormat(const char* format, Args const & ... args) {
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
TwoNums<T> InputManager::GetTwoNums() {
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
// vectorのコピーは遅いので、できればポインタで渡したい
template <typename T>
std::vector<TwoNums<T>> InputManager::GetTwoNums(int num) {
	std::vector<TwoNums<T>> input(num);
	repeat(i, num) {
		auto pair = GetTwoNums<T>();
		input[i] = pair;
	}
	return input;
}

template <typename T>
std::vector<TwoNums<T>> InputManager::GetTwoNumsAsIndex(int num) {
	std::vector<TwoNums<T>> input(num);
	repeat(i, num) {
		auto pair = GetTwoNums<T>();
		input[i] = TwoNums<T>(pair.first - 1, pair.second - 1);
	}
	return input;
}

template <typename T>
ThreeNums<T> InputManager::GetThreeNums() {
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
std::vector<ThreeNums<T>> InputManager::GetThreeNums(int num) {
	std::vector<ThreeNums<T>> input(num);
	repeat(i, num) {
		auto pair = GetThreeNums<T>();
		input[i] = pair;
	}
	return input;
}

template <typename T>
std::vector<T> InputManager::GetNums(int num) {
	std::vector<T> input;
	if (m_isCheckMode) {
		while (num > 0) {
			auto line = PopInputLine();
			auto nums = Split<T>(line);
			std::copy(nums.begin(), nums.end(), std::back_inserter(input));
			num -= (int)nums.size();
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
template <typename T>
std::vector<T> InputManager::GetNumsAsIndex(int num) {
	auto nums = GetNums<T>(num);
	for(auto&& index : nums) {
		index--;
	}
	return nums;
}

template <typename T>
Matrix<T> InputManager::GetMatrix(int h, int w) {
	Matrix<T> mat(h);
	repeat(i, h) {
		mat[i] = GetNums<T>(w);
	}
	return mat;
}

template <typename T>
Matrix<T> InputManager::GetMatrix(TwoNums<int> hw) {
	return GetMatrix<T>(hw.first, hw.second);
}