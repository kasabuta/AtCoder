#include "Questionb208F.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
#include <math.h>
namespace Questionb208F {
namespace {
	const char* INPUT_CASE[] = {
	R"(0 1 2)",
	R"(3 4 2)",
	//R"(1000000000000000000 30 123456)",
	};
	const char* OUTPUT_CASE[] = {
	R"(0)",
	R"(35)",
	//R"(297085514)",
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
	GetInputFormat("%lld %d %lld", &input.N, &input.M, &input.K);
	return input;
}
/* ‰ð“šo—Í */
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	OutputFormat(outStr, "%lld", output.rest);
}
/* ‰ð–@ */
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	const long long perNum = 1000000007;
	std::vector<std::vector<long long>> table;
	repeat(i, input.M + 1) {
		std::vector<long long> lineM;
		lineM.resize(input.N + 1);
		lineM[0] = 0;
		table.push_back(lineM);
	}
	for (auto i = 1; i <= input.N; i++) {
		table[0][i] = std::pow(i, input.K);
		for (auto j = 1; j <= input.M; j++) {
			table[j][i] = table[j - 1][i] + table[j][i - 1];
			if (table[j][i] >= perNum) table[j][i] -= perNum;
		}
	}

	OutputStruct result;
	result.rest = table[input.M][input.N] % perNum;
	return result;
}
}
