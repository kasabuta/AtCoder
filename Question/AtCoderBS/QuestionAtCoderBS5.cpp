#include "QuestionAtCoderBS5.h"
#include "../../Utility/Utility.h"
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
/* ‰ð–@ */
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
