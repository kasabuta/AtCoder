#include "Questionb213B.h"

#include "../../Utility/Utility.h"
namespace Questionb213B {
namespace {
	const char* INPUT_CASE[] = {
	R"(6
1 123 12345 12 1234 123456
)",
	R"(5
3 1 4 15 9
)",
	};
	const char* OUTPUT_CASE[] = {
	R"(3)",
	R"(5)",
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
/* “ü—ÍŽæ“¾ */
InputStruct AtCoderQuestion::Input() {
	InputStruct input;
	m_input.GetInputFormat("%d", &input.num);
	char buf[2000];
	m_input.GetInputFormat("%[^\n]", buf);
	auto inArray = Split(buf, " ");
	std::vector<long long> line;
	for (auto array : inArray) {
		input.score.push_back(std::atoll(array.c_str()));
	}
	return input;
}
/* ‰ð“šo—Í */
void AtCoderQuestion::Output(const OutputStruct& output) {
	m_output.OutputFormat("%d", output.booby);
}

/* ‰ð–@ */
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	long long booby = 0;
	int boobyIndex = -1;
	long long last = 0;
	int lastIndex = -1;

	repeat (i, (int)(input.score.size())) {
		auto score = input.score[i];
		if (score > last) {
			booby = last;
			boobyIndex = lastIndex;
			last = score;
			lastIndex = i;
		}
		else if (score > booby) {
			booby = score;
			boobyIndex = i;
		}
	}

	OutputStruct result;
	result.booby = boobyIndex + 1;
	return result;
}
}
