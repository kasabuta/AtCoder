#include "Questionb234B.h"
#include "../../Utility/Utility.h"
#include<math.h>
namespace Questionb234B {
namespace {
	const char* INPUT_CASE[] = {
	R"(3
0 0
0 1
1 1)",
	R"(5
315 271
-2 -621
-205 -511
-952 482
165 463)",
	};
	const char* OUTPUT_CASE[] = {
	R"(1.4142135624)",
	R"(1455.7159750446)",
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

double GetLength(TwoNums<int> p1, TwoNums<int> p2) {
	double length = 0;
	length += (p1.first - p2.first) * (p1.first - p2.first);
	length += (p1.second - p2.second) * (p1.second - p2.second);
	return std::sqrt(length);
}

/* ‰ð–@ */
void AtCoderQuestion::Solver() {
	auto num = m_input.GetInputInt();
	std::vector<TwoNums<int>> points;
	repeat(i, num) {
		auto point = m_input.GetInputTwoNums<int>();
		points.push_back(point);
	}
	double maxLength = 0;
	repeat(i, num - 1) {
		for (auto j = i + 1; j < num; j++) {
			double length = GetLength(points[i], points[j]);
			if (length > maxLength) {
				maxLength = length;
			}
		}
	}
	m_output.OutputFormat("%lf", maxLength);
}
}
