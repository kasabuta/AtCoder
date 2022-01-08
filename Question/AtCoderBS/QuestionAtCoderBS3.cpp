#include "QuestionAtCoderBS3.h"
#include "../../Utility/Utility.h"
namespace QuestionAtCoderBS3 {
namespace {
	const char* INPUT_CASE[] = {
	R"(101)",
	R"(000)",
	};
	const char* OUTPUT_CASE[] = {
	R"(2)",
	R"(0)",
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
/* ‰ð–@ */
void AtCoderQuestion::Solver() {
	auto line = m_input.GetInputString();
	auto count = 0;
	for (auto chara : line) {
		if (chara == '1') {
			count++;
		}
	}
	m_output.OutputNum(count);
}
}
