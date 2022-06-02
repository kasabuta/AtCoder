#include <string>
#include <vector>
#include <iostream>

#include "InputManager.h"

std::string InputManager::PopInputLine() {
	std::string line;
	if (!m_inputLines.empty()) {
		line = m_inputLines.front();
		m_inputLines.erase(m_inputLines.begin());
	} else {
		assert("reference invalid index in \"m_inputLines\".");
	}
	return line;
}

int InputManager::GetInt() {
	if (m_isCheckMode) {
		auto inputCase = PopInputLine();
		return std::stoi(inputCase);
	} else {
		int tmp;
		std::cin >> tmp;
		return tmp;
	}
}

float InputManager::GetFloat() {
	if (m_isCheckMode) {
		auto inputCase = PopInputLine();
		return std::stof(inputCase);
	} else {
		float tmp;
		std::cin >> tmp;
		return tmp;
	}
}

double InputManager::GetDouble() {
	if (m_isCheckMode) {
		auto inputCase = PopInputLine();
		return std::stod(inputCase);
	} else {
		float tmp;
		std::cin >> tmp;
		return tmp;
	}
}

long long InputManager::GetLongLong() {
	if (m_isCheckMode) {
		auto inputCase = PopInputLine();
		return std::stoll(inputCase);
	} else {
		long long tmp;
		std::cin >> tmp;
		return tmp;
	}
}

std::string InputManager::GetString() {
	if (m_isCheckMode) {
		auto inputCase = PopInputLine();
		return inputCase;
	} else {
		std::string tmp;
		do {
			std::getline(std::cin, tmp);
		} while (tmp == "");
		return tmp;
	}
}
std::vector<std::string> InputManager::GetStrings(int num) {
	std::vector<std::string> out;
	while (num > 0) {
		auto line = GetString();
		auto strings = Split<std::string>(line);
		std::copy(strings.begin(), strings.end(), std::back_inserter(out));
		num -= (int)strings.size();
	}
	return out;
}

std::vector<Edge> InputManager::GetPathWeight(int num) {
	std::vector<Edge> input(num);
	repeat(i, num) {
		auto path = GetThreeNums<int>();
		input[i] = Edge(path.first - 1, path.second - 1, path.third);
	}
	return input;
}

