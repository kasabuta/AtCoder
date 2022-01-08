#include "QuestionAtCoderBS4.h"
#include "../../Utility/Utility.h"
namespace QuestionAtCoderBS4 {
namespace {
	const char* INPUT_CASE[] = {
	R"(3
8 12 40)",
	R"(4
5 6 8 10)",
	R"(6
382253568 723152896 37802240 379425024 404894720 471526144)",
	};
	const char* OUTPUT_CASE[] = {
	R"(2)",
	R"(0)",
	R"(8)",
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
	auto blackboard = m_input.GetInputNums<long long>(num);
	bool result = true;
	auto count = 0;
	while (result) {
		for(auto& n : blackboard) {
			if (n % 2 == 0) {
				n /= 2;
			} else {
				result = false;
			}
		}
		if(result) count++;
	}
	m_output.OutputNum(count);
}
}
