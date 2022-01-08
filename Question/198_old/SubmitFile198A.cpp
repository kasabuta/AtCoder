#include <string>
#include <vector>

#define SIZEOF(a) (sizeof(a)/sizeof(a[0]))

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
		*outString = buf;
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
        if (line.find("const ExecType execType = ExecType::OUTPUT;") != std::string::npos) {
            line = "const ExecType execType = ExecType::ANSWER;";
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


static const int QUESTION_NUM = 6;
static const int TESTCASE_NUM = 3;

template <class InputStruct, class OutputStruct>
class AtCoderQuestionBase {
protected:
	AtCoderQuestionBase()
		: m_isCheck(true)
		, m_inputStock() {};

	/* 解答用の出力とテストケースを使ったチェックを切り替えるための入力関数 */
	template <typename ...Args>
	int InputFormat(const char* format, Args const & ... args);	//

	virtual InputStruct Input() = 0;
	virtual void Output(const OutputStruct& output, std::string* outStr = nullptr) = 0;
	virtual OutputStruct Solver(const InputStruct& input) = 0;

public :
	void Answer();
	bool Check();

private:
	virtual const char* GetInputCase(uint8_t index) const = 0;
	virtual const char* GetOutputCase(uint8_t index) const = 0;

	InputStruct GetInputStruct(int index);	// @Todo m_inputStockを触っているので、厳密にはGet関数ではないしconstにもできない...。
	void SetupInputCase(int index);

	bool m_isCheck;
	std::vector<std::string> m_inputStock;
};


template <class InputStruct, class OutputStruct>
void AtCoderQuestionBase<InputStruct, OutputStruct>::Answer() {
	m_isCheck = false;

	InputStruct input = Input();
	OutputStruct output = Solver(input);
	Output(output);
}

template <class InputStruct, class OutputStruct>
bool AtCoderQuestionBase<InputStruct, OutputStruct>::Check() {
	m_isCheck = true;

	bool checkResult = true;
	for (int i = 0; i < TESTCASE_NUM; i++) {
		InputStruct input = GetInputStruct(i);
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

template <class InputStruct, class OutputStruct>
InputStruct AtCoderQuestionBase<InputStruct, OutputStruct>::GetInputStruct(int index) {
	SetupInputCase(index);
	return Input();
}

template <class InputStruct, class OutputStruct>
void AtCoderQuestionBase<InputStruct, OutputStruct>::SetupInputCase(int index) {
	m_inputStock.clear();

	std::string input = GetInputCase(index);
	auto inputArray = split(input, "\n");
	for (auto line : inputArray) {
		m_inputStock.push_back(line);
	}
}

template <class InputStruct, class OutputStruct>
template<typename ... Args>
int AtCoderQuestionBase<InputStruct, OutputStruct>::InputFormat(const char* format, Args const & ... args) {
	if (m_isCheck) {
		if (!m_inputStock.empty()) {
			auto inputCase = m_inputStock.front();
			m_inputStock.erase(m_inputStock.begin());
			return std::sscanf(inputCase.c_str(), format, args...);
		} else {
			assert("reference invalid index in \"m_inputStock\".");
		}
	} else {
		return std::scanf(format, args...);
	}
	return -1;
}

static const char* contestName = "198";
static const char* questionIndex = "A";

namespace Question198A {

class InputStruct {
public:
	int numSnack;
};

class OutputStruct {
public:
	int numPattern;
};

class AtCoderQuestion : public AtCoderQuestionBase<InputStruct, OutputStruct> {
public:
	AtCoderQuestion() : AtCoderQuestionBase<InputStruct, OutputStruct>() {};

protected:
	InputStruct Input() final override;
	void Output(const OutputStruct& output, std::string* outStr = nullptr) final override;
	OutputStruct Solver(const InputStruct& input) final override;

private:
	const char* GetInputCase(uint8_t index) const override;
	const char* GetOutputCase(uint8_t index) const override;
};
}


namespace Question198A {

namespace {
	const char* INPUT_CASE[] = {
	R"(2)",
	R"(1)",
	R"(3)",
	};
	static_assert(SIZEOF(INPUT_CASE) == TESTCASE_NUM, "num of INPUT_CASE is invalid.");

	const char* OUTPUT_CASE[] = {
	R"(1)",
	R"(0)",
	R"(2)",
	};
	static_assert(SIZEOF(OUTPUT_CASE) == TESTCASE_NUM, "num of OUTPUT_CASE is invalid.");
}	// end of anonymous namespace.

const char* AtCoderQuestion::GetInputCase(uint8_t index) const {
	if (index < TESTCASE_NUM) {
		return INPUT_CASE[index];
	}
	return "";
}
const char* AtCoderQuestion::GetOutputCase(uint8_t index) const {
	if (index < TESTCASE_NUM) {
		return OUTPUT_CASE[index];
	}
	return "";
}

InputStruct AtCoderQuestion::Input() {
	InputStruct input;
	InputFormat("%d", &input.numSnack);
	return input;
}

void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	OutputFormat(outStr, "%d", output.numPattern);
}


OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	OutputStruct result;
	result.numPattern = input.numSnack - 1;
	return result;
}

}

namespace {
enum class ExecType {
	CHECK,
	ANSWER,
	OUTPUT,
};
const ExecType execType = ExecType::ANSWER;
}

int main() {
	Question198A::AtCoderQuestion question;

	switch (execType) {
	case ExecType::CHECK:
		question.Check();
		break;
	case ExecType::ANSWER:
		question.Answer();
		break;
	case ExecType::OUTPUT:
		MakeSubmitFile(contestName, questionIndex);
		break;
	}
	return 0;
}
