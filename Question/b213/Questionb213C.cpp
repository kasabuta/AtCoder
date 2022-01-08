#include "Questionb213C.h"

#include "../../Utility/Utility.h"
#include <algorithm>
namespace Questionb213C {
namespace {
	const char* INPUT_CASE[] = {
	R"(4 5 2
3 2
2 5
)",
	R"(1000000000 1000000000 10
1 1
10 1
100 100
1000 1000
10000 10000
100000 100000
1000000 1000000
10000000 10000000
100000000 100000000
1000000000 1000000000
)",
	};
	const char* OUTPUT_CASE[] = {
	R"(2 1
1 2
)",
	R"(1 1
2 1
3 2
4 3
5 4
6 5
7 6
8 7
9 8
10 9
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
/* “ü—ÍŽæ“¾ */
InputStruct AtCoderQuestion::Input() {
	InputStruct input;
	m_input.GetInputFormat("%lld %lld %d", &input.height, &input.width, &input.enableNum);
	repeat(i, input.enableNum) {
		long long height;
		long long width;
		//GetInputFormat("%lld %lld", &height, &width);
		m_input.GetInputNums2(&height, &width);
		input.heights.push_back(height);
		input.widths.push_back(width);
	}
	return input;
}
/* ‰ð“šo—Í */
void AtCoderQuestion::Output(const OutputStruct& output) {
	for (auto&& card : output.cards) {
		m_output.OutputFormat("%lld %lld\n", card.height, card.width);
	}
}
/* ‰ð–@ */
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	typedef std::pair<int, long long> pair;
	std::vector<pair> heights;
	std::vector<pair> widths;

	OutputStruct result;
	repeat(i, input.enableNum) {
		heights.push_back(pair(i, input.heights[i]));
		widths.push_back(pair(i, input.widths[i]));
		Card card;
		card.height = 0;
		card.width = 0;
		result.cards.push_back(card);
	}

	std::sort(
		heights.begin(),
		heights.end(),
		[](const pair& x, const pair& y) {return x.second < y.second; }
	);

	std::sort(
		widths.begin(),
		widths.end(),
		[](const pair& x, const pair& y) {return x.second < y.second; }
	);

	long long newH = 0;
	long long newW = 0;
	long long tmpH = 0;
	long long tmpW = 0;
	
	repeat(i, input.enableNum) {
		if (tmpH != heights[i].second) {
			newH++;
			tmpH = heights[i].second;
		}
		if (tmpW != widths[i].second) {
			newW++;
			tmpW = widths[i].second;
		}
		result.cards[heights[i].first].height = newH;
		result.cards[widths[i].first].width = newW;
	}
	return result;
}
}
