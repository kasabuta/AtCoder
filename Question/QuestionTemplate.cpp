#include "QuestionTITLEQINDEX.h"

#include "../../Utility/Utility.h"

namespace QuestionTITLEQINDEX {

namespace {
	const char* INPUT_CASE[] = {
	R"()",
	R"()",
	R"()",
	};

	const char* OUTPUT_CASE[] = {
	R"()",
	R"()",
	R"()",
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

int AtCoderQuestion::GetNumTestCase() const {
	return SIZEOF(INPUT_CASE);
}

/* ???@ */
void AtCoderQuestion::Solver() {
	m_input.GetInt();
	m_output.OutputNum(0);
}

}