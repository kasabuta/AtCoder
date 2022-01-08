#include "Questionb206C.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"

#include <algorithm>
namespace Questionb206C {
namespace {
	const char* INPUT_CASE[] = {
	R"(10
1 10 100 1000 10000 100000 1000000 10000000 100000000 1000000000
)",
	R"(20
7 8 1 1 4 9 9 6 8 2 4 1 1 9 5 5 5 3 6 4
)",
	R"(3
1 7 1
)",
	};
	const char* OUTPUT_CASE[] = {
	R"(45)",
	R"(173)",
	R"(2)",
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
	GetInputFormat("%d", &input.length);
	char buf[320000];
	GetInputFormat("%[^\n]", buf);
	auto inArray = split(buf, " ");
	std::vector<long long> line;
	for (auto array : inArray) {
		input.array.push_back(std::atoll(array.c_str()));
	}
	return input;
}
/* âìöèoóÕ */
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	OutputFormat(outStr, "%lld", output.num);
}

long long Factorial(int num) {
	long long result = 1;
	repeat(i, num) {
		result *= (i+1);
	}
	return result;
}

long long Factorial(long long num) {
	long long result = 1;
	repeat(i, num) {
		result *= (i+1);
	}
	return result;
}

int Combination(int all, int select) {
	if (all < select) { return 0; };
	long long result = 1;
	repeat(i, select) {
		result *= (all - i);
	}
	repeat(i, select) {
		result /= (i+1);
	}
	return result;
}

long long Combination(long long all, long long select) {
	if (all < select) { return 0; };
	long long result = 1;
	repeat(i, select) {
		result *= (all - i);
	}
	repeat(i, select) {
		result /= (i + 1);
	}
	return result;
}

/* âñ@ */
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	//std::vector<long long> species;
	//std::vector<int> numSpecies;
	//for (auto num : input.array) {
	//	bool isExist = false;
	//	repeat(i, species.size()){
	//		auto checkedNum = species[i];
	//		if (num == checkedNum) {
	//			numSpecies[i]++;
	//			isExist = true;
	//			break;
	//		}
	//	}
	//	if (!isExist) {
	//		species.push_back(num);
	//		numSpecies.push_back(1);
	//	}
	//}

	OutputStruct result;
	//result.num = Combination(input.length, 2);
	//for (auto numDupli : numSpecies) {
	//	result.num -= Combination(numDupli, 2);
	//}
	auto sortedArr = input.array;
	std::sort(sortedArr.begin(), sortedArr.end());
	std::vector<long long> numDup;
	long long prevNum = 0;
	long long count = 0;
	for (auto num : sortedArr) {
		if (num == prevNum) {
			count++;
		} else {

		}
		prevNum = num;
	}

	return result;
}
}
