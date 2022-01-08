#include "Questionb200C.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
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
