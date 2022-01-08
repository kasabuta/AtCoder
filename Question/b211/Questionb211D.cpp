#include "Questionb211D.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
namespace Questionb211D {
namespace {
	const char* INPUT_CASE[] = {
	R"(4 5
2 4
1 2
2 3
1 3
3 4
)",
	R"(4 3
1 3
2 3
2 4
)",
	R"(2 0
)",
	};
	const char* OUTPUT_CASE[] = {
	R"(2)",
	R"(1)",
	R"(0)",
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
	GetInputFormat("%d %d", &input.numCity, &input.numRoad);
	repeat(i, input.numRoad) {
		InputStruct::path path;
		GetInputFormat("%d %d", &path.from, &path.to);
	}
	return input;
}
/* ‰ð“šo—Í */
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	OutputFormat(outStr, "lld", output.pattern);
}
/* ‰ð–@ */
long long Search(std::vector<std::vector<int>> city, std::vector<long long>* length, std::vector<bool> flag, std::vector<int> que) {
	if (que.size() == 0) { return 0; }
	auto next = que[0];
	que.erase(que.begin());
	if (flag[next]) { return 0; }
	flag[next] = true;

	for (auto&& nextQue : city[next]) {
		if (!flag[nextQue]) { que.push_back(next); }
		if ((*length)[nextQue] > (*length)[next] + 1) {
			(*length)[nextQue] = (*length)[next];
		}
	}

	return Search(city, length, flag, que);
}

OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	std::vector<std::vector<int>> city(input.numCity);
	for (auto road : input.roads) {
		city[road.from].push_back(road.to);
	}

	std::vector<long long> length(input.numCity);
	std::vector<bool> searchedFlag(input.numCity);
	repeat(i, input.numCity) {
		length[i] = 0;
		searchedFlag[i] = false;
	}
	std::vector<int> que;
	que.push_back(0);
	Search(city, &length, searchedFlag, que);

	OutputStruct result;
	return result;
}
}
