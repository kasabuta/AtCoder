#include <string>
#include <vector>

#define SIZEOF(a) (sizeof(a)/sizeof(a[0]))
#define repeat(itr, count) for(auto itr = 0; itr < count; itr++ )

std::vector<std::string> split(std::string str, const char* del);

template <typename ... Args>
std::string format(const char* fmt, Args ... args) {
    size_t len = std::snprintf(nullptr, 0, fmt, args ...);
    std::vector<char> buf(len + 1);
    std::snprintf(&buf[0], len + 1, fmt, args ...);
    return std::string(&buf[0], &buf[0] + len);
}

std::vector<std::string> split(std::string str, const char* separator) {
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
		m_inputLines = split(input, "\n");
	};

	template <typename T>
	T GetInput() { return 0; };

	template <typename ...Args>
	int InputFormat(const char* format, Args const & ... args);

private:
	bool m_isCheckMode;
	std::vector<std::string> m_inputLines;
};

/* 解答用の出力とテストケースを使ったチェックを切り替えるための入力関数 */
template <typename ...Args>
int InputManager::InputFormat(const char* format, Args const & ... args) {
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


template <>
inline int InputManager::GetInput<int>() {
	int tmp;
	if (InputFormat("%d", &tmp) != EOF) {
		return tmp;
	}
	return 0;
}

template <>
inline long long InputManager::GetInput<long long>() {
	long long tmp;
	if (InputFormat("%lld", &tmp) != EOF) {
		return tmp;
	}
	return 0;
}

template <>
inline std::string InputManager::GetInput<std::string>() {
	char buf[MAX_LINE_LENGTH];
	if (InputFormat("%s", buf) != EOF) {
		std::string tmp(buf);
		return tmp;
	}
	return std::string("");
}

template <>
inline std::vector<int> InputManager::GetInput<std::vector<int>>() {
	std::vector<int> input;
	char buf[MAX_LINE_LENGTH];
	if (InputFormat("%s", buf) != EOF) {
		std::string tmp(buf);
		auto arr = split(tmp, " ");
		for (auto num : arr) {
			input.push_back(std::atoi(num.c_str()));
		}
	}
	return input;
}

template <>
inline std::vector<long long> InputManager::GetInput<std::vector<long long>>() {
	std::vector<long long> input;
	char buf[MAX_LINE_LENGTH];
	if (InputFormat("%s", buf) != EOF) {
		std::string tmp(buf);
		auto arr = split(tmp, " ");
		for (auto num : arr) {
			input.push_back(std::atoll(num.c_str()));
		}
	}
	return input;
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
		: m_inputManager()
	{};

	template <typename T>
	T GetInput();

	template <typename ...Args>
	int GetInputFormat(const char* format, Args const & ... args);

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

	InputManager m_inputManager;
};

template <class InputStruct, class OutputStruct>
template <typename T>
T AtCoderQuestionBase<InputStruct, OutputStruct>::GetInput() {
	return m_inputManager.GetInput<T>();
}

template <class InputStruct, class OutputStruct>
template <typename ...Args>
int AtCoderQuestionBase<InputStruct, OutputStruct>::GetInputFormat(const char* format, Args const & ... args) {
	return m_inputManager.InputFormat(format, args...);
}

template <class InputStruct, class OutputStruct>
void AtCoderQuestionBase<InputStruct, OutputStruct>::Answer() {
	m_inputManager.SetCheckMode(false);

	InputStruct input = Input();
	OutputStruct output = Solver(input);
	Output(output);
}

template <class InputStruct, class OutputStruct>
bool AtCoderQuestionBase<InputStruct, OutputStruct>::Check() {
	m_inputManager.SetCheckMode(true);

	bool checkResult = true;
	auto numTestCase = GetNumTestCase();
	for (int i = 0; i < numTestCase; i++) {
		m_inputManager.SetupInputCase(GetInputCase(i));
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

static const char* contestName = "b203";
static const char* questionIndex = "C";
namespace Questionb203C {
/* 入力値の形式 */
class InputStruct {
public:
	long long numFriends;
	long long money;
	struct Friend {
		Friend() {};
		long long village;
		long long money;
		bool operator<(const Friend& right) const {
			return village < right.village;
		}

		bool operator>(const Friend& right) const {
			return village > right.village;
		}
	};
	std::vector<Friend> friends;
};
/* 出力値の形式 */
class OutputStruct {
public:
	long long village;
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
namespace Questionb203C {
namespace {
	const char* INPUT_CASE[] = {
	R"(2 3
2 1
5 10
)",
	R"(5 1000000000
1 1000000000
2 1000000000
3 1000000000
4 1000000000
5 1000000000
)",
	R"(3 2
5 5
2 1
2 2
)",
	};
	const char* OUTPUT_CASE[] = {
	R"(4)",
	R"(6000000000)",
	R"(10)",
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
	GetInputFormat("%lld %lld", &input.numFriends, &input.money);
	repeat(i, input.numFriends) {
		InputStruct::Friend frie;
		GetInputFormat("%lld %lld", &frie.village, &frie.money);
		input.friends.push_back(frie);
	}
	return input;
}
/* 解答出力 */
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	OutputFormat(outStr, "%lld", output.village);
}
/* 解法 */
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	OutputStruct result;
	auto sortedFriends = input.friends;
	std::sort(sortedFriends.begin(), sortedFriends.end());
	result.village = input.money;
	for (auto frie : sortedFriends) {
		if (frie.village <= result.village) {
			result.village += frie.money;
		} else {
			break;
		}
	}
	return result;
}
}

namespace {
const bool IS_CHECK = false;
}

int main() {
	Questionb203C::AtCoderQuestion question;
	if (IS_CHECK) {
		if (question.Check()) {
			MakeSubmitFile(contestName, questionIndex);
		}
	} else {
		question.Answer();
	}
	return 0;
}
