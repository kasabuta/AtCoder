#include "Question198C.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
#include <math.h>
namespace Question198C {
namespace {
	const char* INPUT_CASE[] = {
	R"(100000 100000 100000)",
	R"(5 11 0)",
	R"(3 4 4)",
	};
	const char* OUTPUT_CASE[] = {
	R"(2)",
	R"(3)",
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
	InputFormat("%d %d %d", &input.range, &input.x, &input.y);
	return input;
}
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	OutputFormat(outStr, "%d", output.step);
}
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	long long power = (long long)input.x * (long long)input.x + (long long)input.y * (long long)input.y;
	double distance = sqrt(power);
	OutputStruct result;
	if (distance < input.range) {
		result.step = 2;
	} else {
		result.step = ceil(distance / input.range);
	}
	return result;
}
}
