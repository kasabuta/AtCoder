#include "Questionb234C.h"
#include "../../Utility/Utility.h"
#include <bitset>
namespace Questionb234C {
namespace {
	const char* INPUT_CASE[] = {
	R"(11)",
	R"(923423423420220108)",
	R"(3)",
	};
	const char* OUTPUT_CASE[] = {
	R"(2022)",
	R"(220022020000202020002022022000002020002222002200002022002200)",
	R"(22)",
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

template <typename T>
inline std::string to_bin_str(T n) {
	std::string str;
	while (n > 0) {
		str.push_back('0' + (n & 1));
		n >>= 1;
	}
	std::reverse(str.begin(), str.end());
	return str;
}

/* ‰ð–@ */
void AtCoderQuestion::Solver() {
	auto index = m_input.GetInputLongLong();
	std::string x_bin = to_bin_str(index);
	
	std::string result;
	for (auto chara : x_bin) {
		if (chara == '0') {
			result.push_back('0');
		} else {
			result.push_back('2');
		}
	}

	m_output.OutputFormat(result.c_str());
}
}
