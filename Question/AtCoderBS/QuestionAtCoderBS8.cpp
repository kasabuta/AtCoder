#include "QuestionAtCoderBS8.h"
#include "../../Utility/Utility.h"
namespace QuestionAtCoderBS8 {
namespace {
	const char* INPUT_CASE[] = {
	R"(4
10
8
8
6)",
	R"(3
15
15
15)",
	R"(7
50
30
50
100
50
80
30)",
	};
	const char* OUTPUT_CASE[] = {
	R"(3)",
	R"(1)",
	R"(4)",
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
	auto num = m_input.GetInputInt();
	auto discs = m_input.GetInputNums<int>(num);
	discs = Sort(discs);
	auto prev = -1;
	auto count = 0;
	for (auto disc : discs) {
		if (prev == disc) {
			continue;
		}
		prev = disc;
		count++;
	}
	m_output.OutputNum(count);
}
}
