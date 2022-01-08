#include "QuestionAtCoderBS11.h"
#include "../../Utility/Utility.h"
namespace QuestionAtCoderBS11 {
namespace {
	const char* INPUT_CASE[] = {
	R"(2
3 1 2
6 1 1)",
	R"(1
2 100 100)",
	R"(2
5 1 1
100 1 1)",
	};
	const char* OUTPUT_CASE[] = {
	R"(Yes)",
	R"(No)",
	R"(No)",
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
	auto plans = m_input.GetInputThreeNums<int>(num);
	auto time = 0;
	auto posX = 0;
	auto posY = 0;
	bool result = true;
	repeat(i, num) {
		auto rap = plans[i].first - time;
		auto distance = abs(posX - plans[i].second) + abs(posY - plans[i].third);
		if (distance > rap || (rap - distance) % 2 != 0) {
			result = false;
			break;
		}
		time = plans[i].first;
		posX = plans[i].second;
		posY = plans[i].third;
	}
	m_output.OutputBool(result, YesNo);
}
}
