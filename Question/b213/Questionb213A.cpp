#include "Questionb213A.h"

#include "../../Utility/Utility.h"
namespace Questionb213A {
namespace {
	const char* INPUT_CASE[] = {
	R"(3 6)",
	R"(10 12)",
	};
	const char* OUTPUT_CASE[] = {
	R"(5)",
	R"(6)",
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
/* “ü—ÍŽæ“¾ */
InputStruct AtCoderQuestion::Input() {
	InputStruct input;
	m_input.GetInputFormat("%d %d", &input.A, &input.B);
	return input;
}
/* ‰ð“šo—Í */
void AtCoderQuestion::Output(const OutputStruct& output) {
	m_output.OutputFormat("%d", output.C);
}
/* ‰ð–@ */
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	OutputStruct result;
	result.C = input.A ^ input.B;
	return result;
}
}
