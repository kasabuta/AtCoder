#include <string>
#include <vector>
#include <iostream>

#include "InputManager.h"

int InputManager::GetInputInt() {
	if (m_isCheckMode) {
		if (!m_inputLines.empty()) {
			auto inputCase = m_inputLines.front();
			m_inputLines.erase(m_inputLines.begin());
			return std::atoi(inputCase.c_str());
		}
		else {
			assert("reference invalid index in \"m_inputLines\".");
		}
	} else {
		int tmp;
		std::cin >> tmp;
		return tmp;
	}
}

float InputManager::GetInputFloat() {
	if (m_isCheckMode) {
		if (!m_inputLines.empty()) {
			auto inputCase = m_inputLines.front();
			m_inputLines.erase(m_inputLines.begin());
			return std::atof(inputCase.c_str());
		}
		else {
			assert("reference invalid index in \"m_inputLines\".");
		}
	} else {
		float tmp;
		std::cin >> tmp;
		return tmp;
	}
}

long long InputManager::GetInputLongLong() {
	if (m_isCheckMode) {
		if (!m_inputLines.empty()) {
			auto inputCase = m_inputLines.front();
			m_inputLines.erase(m_inputLines.begin());
			return std::atoll(inputCase.c_str());
		} else {
			assert("reference invalid index in \"m_inputLines\".");
		}
	} else {
		long long tmp;
		std::cin >> tmp;
		return tmp;
	}
}

std::string InputManager::GetInputString() {
	if (m_isCheckMode) {
		if (!m_inputLines.empty()) {
			auto inputCase = m_inputLines.front();
			m_inputLines.erase(m_inputLines.begin());
			return inputCase;
		} else {
			assert("reference invalid index in \"m_inputLines\".");
		}
	} else {
		std::string tmp;
		std::cin >> tmp;
		return tmp;
	}
}

void InputManager::GetInputNums2(int* in1, int* in2) {
	GetInputFormat("%d %d", in1, in2);
}

void InputManager::GetInputNums2(float* in1, float* in2) {
	GetInputFormat("%f %f", in1, in2);
}

void InputManager::GetInputNums2(long long* in1, long long* in2) {
	GetInputFormat("%lld %lld", in1, in2);
}

void InputManager::GetInputNums3(int* in1, int* in2, int* in3) {
	GetInputFormat("%d %d %d", in1, in2, in3);
}

void InputManager::GetInputNums3(float* in1, float* in2, float* in3) {
	GetInputFormat("%f %f %f", in1, in2, in3);
}

void InputManager::GetInputNums3(long long* in1, long long* in2, long long* in3) {
	GetInputFormat("%lld %lld %lld", in1, in2, in3);
}

void InputManager::GetInputNums(std::vector<int>* in, int num) {
	if (m_isCheckMode) {
		if (!m_inputLines.empty()) {
			auto inputCase = m_inputLines.front();
			m_inputLines.erase(m_inputLines.begin());
			repeat(i, num) {
				*in = SplitToInt(inputCase);
			}
		} else {
			assert("reference invalid index in \"m_inputLines\".");
		}
	} else {
		repeat(i, num) {
			int tmp;
			std::cin >> tmp;
			in->push_back(tmp);
		}
	}
}

void InputManager::GetInputNums(std::vector<float>* in, int num) {
	if (m_isCheckMode) {
		if (!m_inputLines.empty()) {
			auto inputCase = m_inputLines.front();
			m_inputLines.erase(m_inputLines.begin());
			repeat(i, num) {
				*in = SplitToFloat(inputCase);
			}
		} else {
			assert("reference invalid index in \"m_inputLines\".");
		}
	} else {
		repeat(i, num) {
			float tmp;
			std::cin >> tmp;
			in->push_back(tmp);
		}
	}
}

void InputManager::GetInputNums(std::vector<long long>* in, int num) {
	if (m_isCheckMode) {
		if (!m_inputLines.empty()) {
			auto inputCase = m_inputLines.front();
			m_inputLines.erase(m_inputLines.begin());
			repeat(i, num) {
				*in = SplitToLongLong(inputCase);
			}
		} else {
			assert("reference invalid index in \"m_inputLines\".");
		}
	} else {
		repeat(i, num) {
			long long tmp;
			std::cin >> tmp;
			in->push_back(tmp);
		}
	}
}
