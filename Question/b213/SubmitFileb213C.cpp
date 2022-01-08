#include <string>
#include <vector>

#define SIZEOF(a) (sizeof(a)/sizeof(a[0]))
#define repeat(itr, count) for(auto itr = 0; itr < count; itr++ )

std::vector<std::string> Split(std::string str, const char* del = " ");
std::vector<int> SplitToInt(std::string str, const char* del = " ");
std::vector<float> SplitToFloat(std::string str, const char* del = " ");
std::vector<long long> SplitToLongLong(std::string str, const char* del = " ");

template <typename ... Args>
std::string format(const char* fmt, Args ... args) {
    size_t len = std::snprintf(nullptr, 0, fmt, args ...);
    std::vector<char> buf(len + 1);
    std::snprintf(&buf[0], len + 1, fmt, args ...);
    return std::string(&buf[0], &buf[0] + len);
}

int RoundUp(float input);
int RoundDown(float input);
int Round(float input);

std::vector<int> Sort(std::vector<int> array);
#include <algorithm>
#include <cmath>

std::vector<std::string> Split(std::string str, const char* separator) {
    size_t pos = 0;
    size_t next = str.find(separator);

    std::vector<std::string> result;

    if (next == std::string::npos) {
        result.push_back(str);
        return result;
    }

    while (next != std::string::npos) {
        std::string subStr(str, pos, next - pos);
        result.push_back(subStr);

        pos = next + 1;
        next = str.find(separator, pos);
    }
    if (pos != str.size()) {
        std::string subStr(str, pos);
        result.push_back(subStr);
    }

    return result;
}

std::vector<int> SplitToInt(std::string str, const char* separator) {
    size_t pos = 0;
    size_t next = str.find(separator);

    std::vector<int> result;

    if (next == std::string::npos) {
        result.push_back(std::atoi(str.c_str()));
        return result;
    }

    while (next != std::string::npos) {
        std::string subStr(str, pos, next - pos);
        result.push_back(std::atoi(subStr.c_str()));

        pos = next + 1;
        next = str.find(separator, pos);
    }
    if (pos != str.size()) {
        std::string subStr(str, pos);
        result.push_back(std::atoi(subStr.c_str()));
    }

    return result;
}

std::vector<float> SplitToFloat(std::string str, const char* separator) {
    size_t pos = 0;
    size_t next = str.find(separator);

    std::vector<float> result;

    if (next == std::string::npos) {
        result.push_back(std::atof(str.c_str()));
        return result;
    }

    while (next != std::string::npos) {
        std::string subStr(str, pos, next - pos);
        result.push_back(std::atof(subStr.c_str()));

        pos = next + 1;
        next = str.find(separator, pos);
    }
    if (pos != str.size()) {
        std::string subStr(str, pos);
        result.push_back(std::atof(subStr.c_str()));
    }

    return result;
}

std::vector<long long> SplitToLongLong(std::string str, const char* separator) {
    size_t pos = 0;
    size_t next = str.find(separator);

    std::vector<long long> result;

    if (next == std::string::npos) {
        result.push_back(std::atoll(str.c_str()));
        return result;
    }

    while (next != std::string::npos) {
        std::string subStr(str, pos, next - pos);
        result.push_back(std::atoll(subStr.c_str()));

        pos = next + 1;
        next = str.find(separator, pos);
    }
    if (pos != str.size()) {
        std::string subStr(str, pos);
        result.push_back(std::atoll(subStr.c_str()));
    }

    return result;
}

int RoundUp(float input) {
    auto result = std::ceil(input);
    return static_cast<int>(result);
}

int RoundDown(float input) {
    auto result = std::floor(input);
    return static_cast<int>(result);
}

int Round(float input) {
    auto result = std::roundf(input);
    return static_cast<int>(result);
}

std::vector<int> Sort(const std::vector<int> array) {
    auto sortedArray = array;
    std::sort(sortedArray.begin(), sortedArray.end());
    return sortedArray;
}

#include <string>

void OutputFormat(std::string* outString, const char* format, ... );

#include <stdarg.h>
#include <stdio.h>

void OutputFormat(std::string* outString, const char* format, ... ) {
	va_list args;
	va_start(args, format);
	std::vprintf(format, args);
	if (outString) {
		char buf[256];
		std::vsprintf(buf, format, args);
		outString->append(buf);
	}
}

#include <string>
#include <vector>
#include <assert.h>


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
#include <string>
#include <vector>
#include <iostream>


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
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
//#include <shlwapi.h>
#include <vector>
//#include <Windows.h>
//
//bool GetFileNames(std::string folderPath, std::vector<std::string>& file_names) {
//    HANDLE hFind;
//    WIN32_FIND_DATA win32fd;
//    std::string search_name = folderPath + "\\*";
//
//    hFind = FindFirstFile(search_name.c_str(), &win32fd);
//
//    if (hFind == INVALID_HANDLE_VALUE) {
//        throw std::runtime_error("file not found");
//        return false;
//    }
//
//    /* 指定のディレクトリ以下のファイル名をファイルがなくなるまで取得する */
//    do {
//        if (win32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
//            /* ディレクトリの場合は何もしない */
//            printf("directory\n");
//        }         else {
//            /* ファイルが見つかったらVector配列に保存する */
//            file_names.push_back(win32fd.cFileName);
//            printf("%s\n", file_names.back().c_str());
//        }
//    } while (FindNextFile(hFind, &win32fd));
//
//    FindClose(hFind);
//
//    return true;
//}

void CombineFile(std::ofstream& ofs, const char* filePath) {
    std::ifstream ifs(filePath, std::ios::in);
    if (!ifs) {
        std::cout << "File Open Error " << std::endl;
        std::printf("%s can not opend.\n", filePath);
        return;
    }
    std::string line;
    while (getline(ifs, line)) {
        if (line.find("#include \"") != std::string::npos) {
            continue;
        }
        if (line == "#pragma once") {
            continue;
        }
        ofs << line.c_str() << std::endl;
    }
}

void MakeSubmitFile(const char* contestName, const char* questionIndex) {
    std::string submitFileName;
    submitFileName = format("Question\\%s\\SubmitFile%s%s.cpp", contestName, contestName, questionIndex);

    std::ofstream ofs(submitFileName);
    if (!ofs) {
        assert("Output File Error");
        return;
    }

    //std::vector <std::string> fileNames;
    //GetFileNames(".\\Utility", fileNames);
    //for (auto fileName : fileNames) {
    //    std::string filePath(".\\Utility\\");
    //    filePath.append(fileName);
    //    CombineFile(ofs, filePath.c_str());
    //}
    // 
    // util
    CombineFile(ofs, "Utility\\Utility.h");
    CombineFile(ofs, "Utility\\Utility.cpp");
    CombineFile(ofs, "Utility\\AtCoderInOut.h");
    CombineFile(ofs, "Utility\\AtCoderInOut.cpp");
    CombineFile(ofs, "Utility\\InputManager.h");
    CombineFile(ofs, "Utility\\InputManager.cpp");
    CombineFile(ofs, "Utility\\MakeSubmitFile.h");

    // base
    CombineFile(ofs, "AtCoderQuestionBase.h");

    // solver
    std::string solverPath = format("Question\\%s\\Question%s%s.h", contestName, contestName, questionIndex);
    CombineFile(ofs, solverPath.c_str());
    solverPath.pop_back();
    solverPath.append("cpp");
    CombineFile(ofs, solverPath.c_str());

	// main
    std::ifstream ifs("main.cpp", std::ios::in);
    if (!ifs) {
        std::cout << "File Open Error " << std::endl;
        std::printf("main.cpp can not opend.\n");
        return;
    }
    std::string line;
    while (getline(ifs, line)) {
        if (line.find("#include \"") != std::string::npos) {
            continue;
        }
        if (line.find("const bool IS_CHECK = true;") != std::string::npos) {
            line = "const bool IS_CHECK = false;";
        }
        ofs << line.c_str() << std::endl;
    }
    std::printf("SubmitFile is created.\n");
}
#include <cassert>
#include <cstdio>
#include <cstring>
#include <stdarg.h>
#include <string>
#include <vector>


template <class InputStruct, class OutputStruct>
class AtCoderQuestionBase {
protected:
	AtCoderQuestionBase()
		: m_input()
	{};

	virtual InputStruct Input() = 0;
	virtual void Output(const OutputStruct& output, std::string* outStr = nullptr) = 0;
	virtual OutputStruct Solver(const InputStruct& input) = 0;

public :
	void Answer();
	bool Check();

private:
	virtual const char* GetInputCase(uint8_t index) const = 0;
	virtual const char* GetOutputCase(uint8_t index) const = 0;
	virtual const int GetNumTestCase() const = 0;

protected:
	InputManager m_input;
};

template <class InputStruct, class OutputStruct>
void AtCoderQuestionBase<InputStruct, OutputStruct>::Answer() {
	m_input.SetCheckMode(false);

	InputStruct input = Input();
	OutputStruct output = Solver(input);
	Output(output);
}

template <class InputStruct, class OutputStruct>
bool AtCoderQuestionBase<InputStruct, OutputStruct>::Check() {
	m_input.SetCheckMode(true);

	bool checkResult = true;
	auto numTestCase = GetNumTestCase();
	for (int i = 0; i < numTestCase; i++) {
		m_input.SetupInputCase(GetInputCase(i));
		InputStruct input = Input();
		OutputStruct output = Solver(input);

		printf("[ Case %d ]\n", i);
		printf("------    my output     ------\n");

		std::string str;
		Output(output, &str);
		printf("\n");

		if (strcmp(str.c_str(), GetOutputCase(i)) == 0) {
			printf("OK\n\n");
		} else {
			checkResult = false;
			printf("------ test case output ------\n");
			printf("%s\n", GetOutputCase(i));
			printf("Case %d is Failed.\n\n", i);
		}
	}

	if (checkResult) {
		printf("***** Check Completed. *****\n");
	} else {
		printf("***** Check Failed. *****\n");
	}

	return checkResult;
}

static const char* contestName = "b213";
static const char* questionIndex = "C";
namespace Questionb213C {
struct Card {
	long long height;
	long long width;
};
/* 入力値の形式 */
class InputStruct {
public:
	long long height;
	long long width;
	int enableNum;
	std::vector<long long> heights;
	std::vector<long long> widths;
};
/* 出力値の形式 */
class OutputStruct {
public:
	std::vector<Card> cards;
};
class AtCoderQuestion : public AtCoderQuestionBase<InputStruct, OutputStruct> {
public:
	AtCoderQuestion() {};
protected:
	InputStruct Input() final override;
	void Output(const OutputStruct& output, std::string* outStr = nullptr) final override;
	OutputStruct Solver(const InputStruct& input) final override;
private:
	const char* GetInputCase(uint8_t index) const final override;
	const char* GetOutputCase(uint8_t index) const final override;
	const int GetNumTestCase() const final override;
};
}
#include <algorithm>
namespace Questionb213C {
namespace {
	const char* INPUT_CASE[] = {
	R"(4 5 2
3 2
2 5
)",
	R"(1000000000 1000000000 10
1 1
10 1
100 100
1000 1000
10000 10000
100000 100000
1000000 1000000
10000000 10000000
100000000 100000000
1000000000 1000000000
)",
	};
	const char* OUTPUT_CASE[] = {
	R"(2 1
1 2
)",
	R"(1 1
2 1
3 2
4 3
5 4
6 5
7 6
8 7
9 8
10 9
)",
	};
	static_assert(SIZEOF(OUTPUT_CASE) == SIZEOF(INPUT_CASE), "num of OUTPUT_CASE is invalid.");
}	// end of anonymous namespace.
const char* AtCoderQuestion::GetInputCase(uint8_t index) const {
	if (index < SIZEOF(INPUT_CASE)) {
		return INPUT_CASE[index];
	}
	return "";
}
const char* AtCoderQuestion::GetOutputCase(uint8_t index) const {
	if (index < SIZEOF(OUTPUT_CASE)) {
		return OUTPUT_CASE[index];
	}
	return "";
}
const int AtCoderQuestion::GetNumTestCase() const {
	return SIZEOF(INPUT_CASE);
}
/* 入力取得 */
InputStruct AtCoderQuestion::Input() {
	InputStruct input;
	m_input.GetInputFormat("%lld %lld %d", &input.height, &input.width, &input.enableNum);
	repeat(i, input.enableNum) {
		long long height;
		long long width;
		//GetInputFormat("%lld %lld", &height, &width);
		m_input.GetInputNums2(&height, &width);
		input.heights.push_back(height);
		input.widths.push_back(width);
	}
	return input;
}
/* 解答出力 */
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	for (auto&& card : output.cards) {
		OutputFormat(outStr, "%lld %lld\n", card.height, card.width);
	}
}
/* 解法 */
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	typedef std::pair<int, long long> pair;
	std::vector<pair> heights;
	std::vector<pair> widths;

	OutputStruct result;
	repeat(i, input.enableNum) {
		heights.push_back(pair(i, input.heights[i]));
		widths.push_back(pair(i, input.widths[i]));
		Card card;
		card.height = 0;
		card.width = 0;
		result.cards.push_back(card);
	}

	std::sort(
		heights.begin(),
		heights.end(),
		[](const pair& x, const pair& y) {return x.second < y.second; }
	);

	std::sort(
		widths.begin(),
		widths.end(),
		[](const pair& x, const pair& y) {return x.second < y.second; }
	);

	long long newH = 0;
	long long newW = 0;
	long long tmpH = 0;
	long long tmpW = 0;
	
	repeat(i, input.enableNum) {
		if (tmpH != heights[i].second) {
			newH++;
			tmpH = heights[i].second;
		}
		if (tmpW != widths[i].second) {
			newW++;
			tmpW = widths[i].second;
		}
		result.cards[heights[i].first].height = newH;
		result.cards[widths[i].first].width = newW;
	}
	return result;
}
}

namespace {
const bool IS_CHECK = false;
}

int main() {
	Questionb213C::AtCoderQuestion question;
	if (IS_CHECK) {
		question.Check();
		MakeSubmitFile(contestName, questionIndex);
	} else {
		question.Answer();
	}
	return 0;
}
