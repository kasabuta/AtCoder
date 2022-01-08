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

template <typename T>
std::vector<T> Sort(std::vector<T> array);
template <typename T>
std::vector<int> SortIndex(const std::vector<T> array);

template <typename T>
struct TwoNums {
    T first;
    T second;

    TwoNums()
        : first(0)
        , second(0)
    {}
};

template <typename T>
struct ThreeNums {
    T first;
    T second;
    T third;

    ThreeNums()
        : first(0)
        , second(0)
        , third(0)
    {}
};

struct Edge {
    int from;
    int to;

    Edge()
        : from()
        , to()
    {}
};

std::vector<std::vector<int>> MakeGraph(std::vector<Edge> edges, int size);
std::vector<std::vector<int>> MakeGraphDirected(std::vector<Edge> edges, int size);
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

template <typename T>
std::vector<T> Sort(const std::vector<T> array) {
    auto sortedArray = array;
    std::sort(sortedArray.begin(), sortedArray.end());
    return sortedArray;
}

template <typename T>
std::vector<int> SortIndex(const std::vector<T> array) {
    auto length = array.size();
    int indexArray[length];
    repeat(i, length) {
        indexArray[i].index = i;
    }
    std::sort(
        indexArray.begin(),
        indexArray.end(),
        [array](const int& x, const int& y) {return array[x] < array[y]; }
    );
    return indexArray;
}

std::vector<std::vector<int>> MakeGraph(std::vector<Edge> edges, int size) {
    auto length = edges.size();
    std::vector<std::vector<int>> graph;
    graph.resize(size);
    repeat(i, length) {
        graph[edges[i].from].push_back(edges[i].to);
        graph[edges[i].to].push_back(edges[i].from);
    }
    return graph;
}

std::vector<std::vector<int>> MakeGraphDirected(std::vector<Edge> edges, int size) {
    auto length = edges.size();
    std::vector<std::vector<int>> graph;
    graph.resize(size);
    repeat(i, length) {
        graph[edges[i].from].push_back(edges[i].to);
    }
    return graph;

}

#include <string>
#include <vector>
#include <assert.h>
#include <iostream>
#include <sstream>


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

	std::string PopInputLine();

	int GetInputInt();
	float GetInputFloat();
	long long GetInputLongLong();
	std::string GetInputString();

	template <typename ...Args>
	int GetInputFormat(const char* format, Args const & ... args);

	template <typename T>
	TwoNums<T> GetInputTwoNums();

	template <typename T>
	ThreeNums<T> GetInputThreeNums();

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
std::vector<T> InputManager::GetInputNums(int num) {
	std::vector<T> input;
	if (m_isCheckMode) {
		auto line = PopInputLine();
		std::istringstream s(line);
		repeat(i, num) {
			T tmp;
			s >> tmp;
			input.push_back(tmp);
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
#include <string>
#include <vector>
#include <iostream>


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
		return std::atoi(inputCase.c_str());
	} else {
		int tmp;
		std::cin >> tmp;
		return tmp;
	}
}

float InputManager::GetInputFloat() {
	if (m_isCheckMode) {
		auto inputCase = PopInputLine();
		return std::atof(inputCase.c_str());
	} else {
		float tmp;
		std::cin >> tmp;
		return tmp;
	}
}

long long InputManager::GetInputLongLong() {
	if (m_isCheckMode) {
		auto inputCase = PopInputLine();
		return std::atoll(inputCase.c_str());
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

#include <string>
#include <vector>
#include <assert.h>


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

	void OutputNums(const std::vector<int> out);
	void OutputNums(const std::vector<float> out);
	void OutputNums(const std::vector<long long> out);

private:
	bool m_isCheckMode;
	std::string m_outputLine;
};
#include <vector>
#include <iostream>
#include <stdarg.h>


void OutputManager::Print() const {
	std::printf("%s", m_outputLine.c_str());
}

void OutputManager::Reset() {
	m_outputLine.clear();
}

void OutputManager::OutputFormat(const char* format, ...) {
	va_list args;
	va_start(args, format);

	char buf[256];
	std::vsprintf(buf, format, args);
	m_outputLine.append(buf);
}

void OutputManager::OutputNum(const int num) {
	m_outputLine.append(std::to_string(num));
	m_outputLine.append("\n");
}

void OutputManager::OutputNum(const float num) {
	m_outputLine.append(std::to_string(num));
	m_outputLine.append("\n");
}

void OutputManager::OutputNum(const long long num) {
	m_outputLine.append(std::to_string(num));
	m_outputLine.append("\n");
}

void OutputManager::OutputNums(const std::vector<int> out) {
	repeat(i, out.size()) {
		OutputNum(out[i]);
	}
}

void OutputManager::OutputNums(const std::vector<float> out) {
	repeat(i, out.size()) {
		OutputNum(out[i]);
	}
}

void OutputManager::OutputNums(const std::vector<long long> out) {
	repeat(i, out.size()) {
		OutputNum(out[i]);
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
    CombineFile(ofs, "Utility\\InputManager.h");
    CombineFile(ofs, "Utility\\InputManager.cpp");
    CombineFile(ofs, "Utility\\OutputManager.h");
    CombineFile(ofs, "Utility\\OutputManager.cpp");
    CombineFile(ofs, "Utility\\MakeSubmitFile.h");

    // base
    CombineFile(ofs, "AtCoderQuestionBase.h");
    CombineFile(ofs, "AtCoderQuestionBase.cpp");

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


class AtCoderQuestionBase {
protected:
	AtCoderQuestionBase()
		: m_input()
		, m_output()
	{};

	virtual void Solver() = 0;

public :
	void Answer();
	bool Check();

private:
	virtual const char* GetInputCase(uint8_t index) const = 0;
	virtual const char* GetOutputCase(uint8_t index) const = 0;
	virtual const int GetNumTestCase() const = 0;

protected:
	InputManager m_input;
	OutputManager m_output;
};



void AtCoderQuestionBase::Answer() {
	m_input.SetCheckMode(false);

	Solver();
	m_output.Print();
}

bool AtCoderQuestionBase::Check() {
	m_input.SetCheckMode(true);

	bool checkResult = true;
	auto numTestCase = GetNumTestCase();
	for (int i = 0; i < numTestCase; i++) {
		m_input.SetupInputCase(GetInputCase(i));
		m_output.Reset();
		Solver();

		printf("[ Case %d ]\n", i);
		printf("------    my output     ------\n");

		m_output.Print();
		printf("\n");

		if (strcmp(m_output.GetOutput().c_str(), GetOutputCase(i)) == 0) {
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
		printf("*****  Check Failed.   *****\n");
	}

	return checkResult;
}
static const char* contestName = "AtCoderBS";
static const char* questionIndex = "5";
namespace QuestionAtCoderBS5 {
class AtCoderQuestion : public AtCoderQuestionBase {
public:
	AtCoderQuestion() {};
protected:
	void Solver() final override;
private:
	const char* GetInputCase(uint8_t index) const final override;
	const char* GetOutputCase(uint8_t index) const final override;
	const int GetNumTestCase() const final override;
};
}
namespace QuestionAtCoderBS5 {
namespace {
	const char* INPUT_CASE[] = {
	R"(2
2
2
100)",
	R"(5
1
0
150)",
	R"(30
40
50
6000)",
	};
	const char* OUTPUT_CASE[] = {
	R"(2)",
	R"(0)",
	R"(213)",
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
/* 解法 */
void AtCoderQuestion::Solver() {
	auto a = m_input.GetInputInt();
	auto b = m_input.GetInputInt();
	auto c = m_input.GetInputInt();
	auto x = m_input.GetInputInt() / 50;

	auto count = 0;
	repeat(i, RoundDown(x / 10) + 1) {
		if (i > a) break;

		auto rest = x - i * 10;
		repeat(j, RoundDown(rest / 2) + 1) {
			if (j > b) break;

			auto rest2 = rest - j * 2;
			if (rest2 <= c) {
				count++;
			}
		}
	}

	m_output.OutputNum(count);
}
}

namespace {
const bool IS_CHECK = false;
}

int main() {
	QuestionAtCoderBS5::AtCoderQuestion question;
	if (IS_CHECK) {
		if (question.Check()) {
			MakeSubmitFile(contestName, questionIndex);
		}
	} else {
		question.Answer();
	}
	return 0;
}
