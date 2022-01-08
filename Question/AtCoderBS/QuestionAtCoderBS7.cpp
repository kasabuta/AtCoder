#include "QuestionAtCoderBS7.h"
#include "../../Utility/Utility.h"
namespace QuestionAtCoderBS7 {
namespace {
	const char* INPUT_CASE[] = {
	R"(2
3 1)",
	R"(3
2 7 4)",
	R"(4
20 18 2 18)",
	};
	const char* OUTPUT_CASE[] = {
	R"(2)",
	R"(5)",
	R"(18)",
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
	auto cards = m_input.GetInputNums<int>(num);
	cards = SortInv(cards);
	bool isAlice = true;
	auto alice = 0;
	auto bob = 0;
	for (auto card : cards) {
		if (isAlice) {
			alice += card;
		} else {
			bob += card;
		}
		isAlice = !isAlice;
	}
	m_output.OutputNum(alice - bob);
}
}
