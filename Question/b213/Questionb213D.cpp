#include "Questionb213D.h"

#include "../../Utility/Utility.h"
namespace Questionb213D {
namespace {
	const char* INPUT_CASE[] = {
	R"(4
1 2
4 2
3 1
)",
	R"(5
1 2
1 3
1 4
1 5
)",
	};
	const char* OUTPUT_CASE[] = {
	R"(1 2 4 2 1 3 1 )",
	R"(1 2 1 3 1 4 1 5 1 )",
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
	m_input.GetInputFormat("%d", &input.numCity);
	repeat(i, input.numCity - 1) {
		Road road;
		m_input.GetInputFormat("%d %d", &road.from, &road.to);
		road.from--;
		road.to--;
		input.roads.push_back(road);
	}
	return input;
}
/* ‰ð“šo—Í */
void AtCoderQuestion::Output(const OutputStruct& output) {
	for (auto& city : output.cities) {
		m_output.OutputFormat("%d ", city + 1);
	}
}
/* ‰ð–@ */

struct City {
	bool visited;
	int firstFrom;
	std::vector<int> next;

	City() :
		visited(false),
		firstFrom(-1),
		next() {}
};

void Visit(std::vector<City>* cities, std::vector<int>* path) {
	int currentCity = path->back();
	bool isFinished = true;
	for (auto&& next : (*cities)[currentCity].next) {
		if (!(*cities)[next].visited) {
			isFinished = false;
			(*path).push_back(next);
			(*cities)[next].visited = true;
			(*cities)[next].firstFrom = currentCity;
			break;
		}
	}
	if (isFinished) {
		if (currentCity == 0) {
			return;
		} else {
			(*path).push_back((*cities)[currentCity].firstFrom);
		}
	}

	Visit(cities, path);
}

OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {

	std::vector<City> city(input.numCity);

	for(auto&& road : input.roads) {
		city[road.from].next.push_back(road.to);
		city[road.to].next.push_back(road.from);
	}
	std::vector<int> path;
	path.push_back(0);
	city[0].visited = true;
	Visit(&city, &path);

	OutputStruct result;
	result.cities = path;
	return result;
}
}
