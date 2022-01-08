#include "Questionb208C.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
#include <iostream>
#include <algorithm>
namespace Questionb208C {
namespace {
	const char* INPUT_CASE[] = {
	R"(2 7
1 8
)",
	R"(1 3
33
)",
	R"(7 1000000000000
99 8 2 4 43 5 3
)",
	};
	const char* OUTPUT_CASE[] = {
	R"(4
3
)",
	R"(3
)",
	R"(142857142857
142857142857
142857142858
142857142857
142857142857
142857142857
142857142857
)",
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
/* ì¸óÕéÊìæ */
InputStruct AtCoderQuestion::Input() {
	InputStruct input;
	GetInputFormat("%d %lld", &input.population, &input.candy);

	repeat(i, input.population) {
		long long tmp;
		std::cin >> tmp;
		input.ids.push_back(tmp);
	}
	return input;
}
/* âìöèoóÕ */
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	for (auto num : output.num) {
		OutputFormat(outStr, "%lld\n", num);
	}
}
/* âñ@ */
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	OutputStruct result;
	auto baseNum = input.candy / input.population;
	auto sortedIds = input.ids;
	std::sort(sortedIds.begin(), sortedIds.end());
	auto maxId = sortedIds[input.candy - baseNum * input.population];
	repeat(i, input.population) {
		if (input.ids[i] < maxId) {
			result.num.push_back(baseNum + 1);
		} else {
			result.num.push_back(baseNum);
		}
	}
	return result;
}
}
