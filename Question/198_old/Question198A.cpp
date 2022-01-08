#include "Question198A.h"

#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"

namespace Question198A {

namespace {
	const char* INPUT_CASE[] = {
	R"(2)",
	R"(1)",
	R"(3)",
	};

	const char* OUTPUT_CASE[] = {
	R"(1)",
	R"(0)",
	R"(2)",
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
	InputFormat("%d", &input.numSnack);
	return input;
}

void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	OutputFormat(outStr, "%d", output.numPattern);
}


OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	OutputStruct result;
	result.numPattern = input.numSnack - 1;
	return result;
}

}