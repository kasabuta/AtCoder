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

int InputManager::GetInputInt() {
	if (m_isCheckMode) {
		auto inputCase = PopInputLine();
		return std::stoi(inputCase);
	} else {
		int tmp;
		std::cin >> tmp;
		return tmp;
	}
}

float InputManager::GetInputFloat() {
	if (m_isCheckMode) {
		auto inputCase = PopInputLine();
		return std::stof(inputCase);
	} else {
		float tmp;
		std::cin >> tmp;
		return tmp;
	}
}

double InputManager::GetInputDouble() {
	if (m_isCheckMode) {
		auto inputCase = PopInputLine();
		return std::stod(inputCase);
	} else {
		float tmp;
		std::cin >> tmp;
		return tmp;
	}
}

long long InputManager::GetInputLongLong() {
	if (m_isCheckMode) {
		auto inputCase = PopInputLine();
		return std::stoll(inputCase);
	} else {
		long long tmp;
		std::cin >> tmp;
		return tmp;
	}
}

std::string InputManager::GetInputString() {
	if (m_isCheckMode) {
		auto inputCase = PopInputLine();
		return inputCase;
	} else {
		std::string tmp;
		std::cin >> tmp;
		return tmp;
	}
}
