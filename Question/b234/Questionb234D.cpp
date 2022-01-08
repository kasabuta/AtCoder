#include "Questionb234D.h"
#include "../../Utility/Utility.h"
namespace Questionb234D {
namespace {
	const char* INPUT_CASE[] = {
	R"(3 2
1 2 3)",
	R"(11 5
3 7 2 5 11 6 1 9 8 10 4)",
	};
	const char* OUTPUT_CASE[] = {
	R"(1
2)",
	R"(2
3
3
5
6
7
7)",
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
	auto nums = m_input.GetInputNums<int>(pair.first);
	std::vector<int> subvec(nums.begin(), nums.begin() + pair.second);
	subvec = SortInv(subvec);
	m_output.OutputNum(subvec[pair.second - 1]);

	for (auto i = pair.second; i < pair.first; i++) {
		if (nums[i] > subvec[pair.second - 1]) {
			for (auto j = 0; j < pair.second; j++) {
				if (nums[i] < subvec[j]) {
					continue;
				}
				subvec.insert(subvec.begin() + j, nums[i]);
				break;
			}
		}
		m_output.OutputNum(subvec[pair.second - 1]);
	}
}
}
