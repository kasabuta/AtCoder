#include "Questionb203D.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
#include <algorithm>
namespace Questionb203D {
namespace {
	const char* INPUT_CASE[] = {
	R"(3 2
1 7 0
5 8 11
10 4 2
)",
	R"(3 3
1 2 3
4 5 6
7 8 9
)",
	};
	const char* OUTPUT_CASE[] = {
	R"(4)",
	R"(5)",
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
	GetInputFormat("%d %d", &input.parkSize, &input.pondSize);
	repeat(i, input.parkSize) {
		auto hori = GetInput<std::string>();
		auto horiVec = split(hori, " ");
		std::vector<long long> line;
		for (auto height : horiVec) {
			line.push_back(std::atoll(height.c_str()));
		}
		input.height.push_back(line);
	}
	return input;
}
/* âìöèoóÕ */
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	OutputFormat(outStr, "%lld", output.minCenter);
}

int RoundDown(float num) {
	return num;
}

/* âñ@ */
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	std::vector<long long> cornerArray;
	repeat(i, input.pondSize) {
		repeat(j, input.pondSize) {
			cornerArray.push_back(input.height[i][j]);
		}
	}
	std::sort(cornerArray.begin(), cornerArray.end());

	std::vector<std::vector<long long>> middleTable;
	auto cornerMiddle = cornerArray[RoundDown(input.pondSize * input.pondSize * 0.5f)];
	auto selectable = input.parkSize - input.pondSize;
	for (auto i = 1; i < selectable; i++) {
		std::vector<long long> line;
		line.resize(selectable);
		line[0] = middleTable[i][0]
		middleTable.push_back(line);


	}
	repeat(i, selectable) {
		repeat(j, selectable) {
			if (j == 0) {

			}
			long long minus = 0;
			long long plus = 0;
			repeat(k, input.pondSize) {
				minus += input.height[i][j];
				plus  += input.height[][];
			}

			if()
		}
	}

	OutputStruct result;
	return result;
}
}
