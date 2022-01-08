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
//    /* �w��̃f�B���N�g���ȉ��̃t�@�C�������t�@�C�����Ȃ��Ȃ�܂Ŏ擾���� */
//    do {
//        if (win32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
//            /* �f�B���N�g���̏ꍇ�͉������Ȃ� */
//            printf("directory\n");
//        }         else {
//            /* �t�@�C��������������Vector�z��ɕۑ����� */
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
        if (line.find("bool isCheck = true;") != std::string::npos) {
            line = "bool isCheck = false; ";
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
		: m_numTestCase()
		, m_isCheck(true)
		, m_inputStock() {};

	/* �𓚗p�̏o�͂ƃe�X�g�P�[�X���g�����`�F�b�N��؂�ւ��邽�߂̓��͊֐� */
	template <typename ...Args>
	int InputFormat(const char* format, Args const & ... args);	//

	virtual InputStruct Input() = 0;
	virtual void Output(const OutputStruct& output, std::string* outStr = nullptr) = 0;
	virtual OutputStruct Solver(const InputStruct& input) = 0;

	int m_numTestCase;

public :
	void Answer();
	bool Check();

private:
	virtual const char* GetInputCase(uint8_t index) const = 0;
	virtual const char* GetOutputCase(uint8_t index) const = 0;

	InputStruct GetInputStruct(int index);	// @Todo m_inputStock��G���Ă���̂ŁA�����ɂ�Get�֐��ł͂Ȃ���const�ɂ��ł��Ȃ�...�B
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
	for (int i = 0; i < m_numTestCase; i++) {
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
static const char* contestName = "b200";
static const char* questionIndex = "C";
namespace Questionb200C {
class InputStruct {
public:
	int num;
	std::vector<long long> array;
};
class OutputStruct {
public:
	long long count;
};
class AtCoderQuestion : public AtCoderQuestionBase<InputStruct, OutputStruct> {
public:
	AtCoderQuestion();
protected:
	InputStruct Input() final override;
	void Output(const OutputStruct& output, std::string* outStr = nullptr) final override;
	OutputStruct Solver(const InputStruct& input) final override;
private:
	const char* GetInputCase(uint8_t index) const override;
	const char* GetOutputCase(uint8_t index) const override;
};
}
namespace Questionb200C {
namespace {
	const char* INPUT_CASE[] = {
	R"(6
123 223 123 523 200 2000
)",
	R"(5
1 2 3 4 5
)",
	R"(8
199 100 200 400 300 500 600 200
)",
	};
	const char* OUTPUT_CASE[] = {
	R"(4)",
	R"(0)",
	R"(9)",
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
AtCoderQuestion::AtCoderQuestion() : AtCoderQuestionBase<InputStruct, OutputStruct>() {
	m_numTestCase = SIZEOF(INPUT_CASE);
}
InputStruct AtCoderQuestion::Input() {
	InputStruct input;
	InputFormat("%d\n", &input.num);
	char buf[256];
	InputFormat("%[^\n]", buf);
	auto strArray = split(buf, " ");
	for (auto arr : strArray) {
		input.array.push_back(std::atoll(arr.c_str()));
	}
	return input;
}
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	OutputFormat(outStr, "%lld", output.count);
}
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	std::vector<std::vector<int>> count;
	count.resize(200);
	repeat(i, input.num) {
		count[input.array[i] % 200].push_back(input.array[i]);
	}

	OutputStruct result;
	result.count = 0;
	repeat(i, 200) {
		auto modCount = count[i].size();
		if (modCount >= 2) {
			result.count += modCount * (modCount - 1) / 2;
		}
	}

	return result;
}
}

int main() {
	Questionb200C::AtCoderQuestion question;
bool isCheck = false; 
	if (isCheck) {
		if (question.Check()) {
			MakeSubmitFile(contestName, questionIndex);
		}
	} else {
		question.Answer();
	}
	return 0;
}
