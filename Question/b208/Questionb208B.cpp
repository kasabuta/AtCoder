#include "Questionb208B.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
namespace Questionb208B {
namespace {
	const char* INPUT_CASE[] = {
	R"(9)",
	R"(119)",
	R"(10000000)",
	};
	const char* OUTPUT_CASE[] = {
	R"(3)",
	R"(10)",
	R"(24)",
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
	GetInputFormat("%lld", &input.price);
	return input;
}
/* ‰ð“šo—Í */
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	OutputFormat(outStr, "%d", output.numCoins);
}
/* ‰ð–@ */
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	std::vector<long long> coinValue;
	long long value = 1;
	repeat(i, 10) {
		value *= (i+1);
		coinValue.push_back(value);
	}

	OutputStruct result;
	result.numCoins = 0;
	long long restPrice = input.price;
	for (int i = coinValue.size() - 1; i >= 0; i--) {
		if (restPrice < coinValue[i]) {
			continue;
		}
		int curCoinNum = RoundDown(restPrice / coinValue[i]);
		if (curCoinNum > 100) {
			curCoinNum = 100;
		}
		restPrice -= coinValue[i] * curCoinNum;
		result.numCoins += curCoinNum;
		if (restPrice == 0) {
			break;
		}
	}
	return result;
}
}
