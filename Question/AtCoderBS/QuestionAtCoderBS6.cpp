#include "QuestionAtCoderBS6.h"
#include "../../Utility/Utility.h"
namespace QuestionAtCoderBS6 {
namespace {
	const char* INPUT_CASE[] = {
	R"(20 2 5)",
	R"(10 1 2)",
	R"(100 4 16)",
	};
	const char* OUTPUT_CASE[] = {
	R"(84)",
	R"(13)",
	R"(4554)",
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
	auto nums = m_input.GetInputThreeNums<int>();
	auto result = 0;
	for (auto i = 1; i <= nums.first; i++) {
		auto digits = GetDigits(i);
		auto digitSum = 0;
		for (auto dig : digits) {
			digitSum += dig;
		}
		if (digitSum >= nums.second && digitSum <= nums.third) {
			result += i;
		}
	}
	m_output.OutputNum(result);
}
}
