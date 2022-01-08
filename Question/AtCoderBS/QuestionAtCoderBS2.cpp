#include "QuestionAtCoderBS2.h"
#include "../../Utility/Utility.h"
namespace QuestionAtCoderBS2 {
namespace {
	const char* INPUT_CASE[] = {
	R"(3 4)",
	R"(1 21)",
	};
	const char* OUTPUT_CASE[] = {
	R"(Even)",
	R"(Odd)",
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
	if (pair.first % 2 == 0 || pair.second % 2 == 0) {
		m_output.OutputFormat("Even");
	} else {
		m_output.OutputFormat("Odd");
	}
}
}
