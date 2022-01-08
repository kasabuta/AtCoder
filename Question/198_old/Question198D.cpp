#include "Question198D.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
#include <math.h>
namespace Question198D {
namespace {
	const char* INPUT_CASE[] = {
	R"(aaaaaaaaaa
bbbbbbbbbb
cccccccccc
)",
	R"(abcd
efgh
ijkl
)",
	R"(send
more
money
)",
	};
	const char* OUTPUT_CASE[] = {
	R"(1111111111
2222222222
3333333333)",
	R"(UNSOLVABLE)",
	R"(9567
1085
10652)",
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
	input.str.resize(3);
	char buf[64];
	InputFormat("%s", buf);
	input.str[0] = buf;
	InputFormat("%s", buf);
	input.str[1] = buf;
	InputFormat("%s", buf);
	input.str[2] = buf;

	return input;
}
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	if (output.isSolved) {
		OutputFormat(outStr, "%lld\n%lld\n%lld", output.ans1, output.ans2, output.ans3);
	} else {
		OutputFormat(outStr, "UNSOLVABLE");
	}
}

struct Pair {
	char chara;
	int num;
};

const int NOTSET = -1;

class Pairs {
public:
	Pairs() {}

	std::vector<Pair> pairs;
	std::string chars;

	Pair* Find(char chr) {
		for (auto&& pair : pairs) {
			if (pair.chara == chr) {
				return &pair;
			}
		}
		return nullptr;
	}

	bool IsUsedNum(int num) {
		for (auto&& pair : pairs) {
			if (pair.num == num) {
				return true;
			}
		}
		return false;
	}

	void Add(char chr) {
		if (auto&& pair = Find(chr)) {
			return;
		} else {
			Pair newPair = { chr };
			pairs.push_back(newPair);
			chars.push_back(chr);
		}
	}

	char GetChar(int index) {
		return chars[index];
	}

	bool SetNum(char chr, int num) {
		if (IsUsedNum(num)) {
			return false;
		}
		if (auto&& pair = Find(chr)) {
			if (pair->num == NOTSET) {
				pair->num = num;
				return true;
			}
		}
		return false;
	}

	void ClearNum() {
		for (auto&& pair : pairs) {
			pair.num = NOTSET;
		}
	}

	void ClearNum(char chr) {
		if (auto&& pair = Find(chr)) {
			pair->num = NOTSET;
		}
	}

	bool IsAllSet() {
		for (auto&& pair : pairs) {
			if (pair.num == NOTSET) {
				return false;
			}
		}
		return true;
	}
};

bool CheckCondition(const InputStruct& input, Pairs& pairs, OutputStruct* result){
	if (result->isSolved) {
		return true;
	}
	if (!pairs.IsAllSet()) {
		return false;
	}

	long long N[3];
	bool isValidNum = true;
	repeat(i, 3) {
		// 最上位の桁チェック
		if (pairs.Find(input.str[i][0])->num == 0) {
			isValidNum = false;
			break;
		}
		N[i] = 0;
		repeat(j, input.str[i].length()) {
			auto digit = input.str[i].length() - 1 - j;
			N[i] += (long long)(pairs.Find(input.str[i][j])->num) * pow(10, digit);
		}
	}
	if (isValidNum) {
		if (N[0] + N[1] == N[2]) {
			result->isSolved = true;
			result->ans1 = N[0];
			result->ans2 = N[1];
			result->ans3 = N[2];
			return true;
		}
	}
	return false;
}

// pairs.charsのindex文字目について総当り
// まだ数式が完成していなければ次の文字を総当りする
void SetNextNum(const InputStruct& input, Pairs* pairs, const int index, OutputStruct* result) {
	repeat(num, 10) {
		if (pairs->IsUsedNum(num)) {
			continue;
		}
		auto character = pairs->GetChar(index);
		pairs->SetNum(character, num);
		if (!(pairs->IsAllSet())) {
			if (index + 1 < pairs->chars.length()) {
				SetNextNum(input, pairs, index + 1, result);
			}
		}
		if (CheckCondition(input, *pairs, result)) {
			return;
		} else {
			pairs->ClearNum(character);
		}
	}
}

OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {

	Pairs pairs;
	repeat(itr, 3) {
		repeat(index, input.str[itr].length()) {
			pairs.Add(input.str[itr][index]);
		}
	}

	OutputStruct result;
	result.isSolved = false;
	if (pairs.chars.length() <= 10) {
		pairs.ClearNum();
		SetNextNum(input, &pairs, 0, &result);
	}
	return result;
}
}
