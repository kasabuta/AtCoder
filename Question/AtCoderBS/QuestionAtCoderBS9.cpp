#include "QuestionAtCoderBS9.h"
#include "../../Utility/Utility.h"
namespace QuestionAtCoderBS9 {
namespace {
	const char* INPUT_CASE[] = {
	R"(9 45000)",
	R"(20 196000)",
	R"(1000 1234000)",
	R"(2000 20000000)",
	};
	const char* OUTPUT_CASE[] = {
	R"(4 0 5)",
	R"(-1 -1 -1)",
	R"(14 27 959)",
	R"(2000 0 0)",
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
	auto pair = m_input.GetInputTwoNums<int>();
	auto value = pair.second;
	for (auto man = RoundDown(value / 10000); man >= 0; man--) {
		if (man > pair.first) {
			break;
		}
		auto rest = value - man * 10000;
		for (auto sen5 = RoundDown(rest / 5000); sen5 >= 0; sen5--) {
			auto sen = (rest - sen5 * 5000) / 1000;
			if (man + sen5 + sen == pair.first) {
				m_output.OutputFormat("%d %d %d", man, sen5, sen);
				return;
			}
		}
	}
	m_output.OutputFormat("-1 -1 -1");
}
}
