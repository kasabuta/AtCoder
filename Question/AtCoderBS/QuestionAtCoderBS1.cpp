#include "QuestionAtCoderBS1.h"
#include "../../Utility/Utility.h"
namespace QuestionAtCoderBS1 {
namespace {
	const char* INPUT_CASE[] = {
	R"(1
2 3
test
)",
	R"(72
128 256
myonmyon
)",
	};
	const char* OUTPUT_CASE[] = {
	R"(6 test)",
	R"(456 myonmyon)",
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
	auto pair = m_input.GetInputTwoNums<int>();
	auto sum = a + pair.first + pair.second;
	m_output.OutputFormat("%d %s", sum, m_input.GetInputString().c_str());
}
}
