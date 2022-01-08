#include "Questionb234A.h"
#include "../../Utility/Utility.h"
namespace Questionb234A {
namespace {
	const char* INPUT_CASE[] = {
	R"(0)",
	R"(3)",
	R"(10)",
	};
	const char* OUTPUT_CASE[] = {
	R"(1371)",
	R"(722502)",
	R"(1111355571)",
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

long long Func(long long t){
	long long result = (t * t) + t * 2 + 3;
	return result;
}

/* ‰ð–@ */
void AtCoderQuestion::Solver() {
	auto t = m_input.GetInputInt();
	auto result = Func((Func(Func(t) + t) + Func(Func(t))));
	m_output.OutputNum(result);
}
}
