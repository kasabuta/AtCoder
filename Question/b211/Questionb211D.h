#pragma once
#include "../../AtCoderQuestionBase.h"
static const char* contestName = "b211";
static const char* questionIndex = "D";
namespace Questionb211D {
/* 入力値の形式 */
class InputStruct {
public:
	struct path {
		int from;
		int to;
	};

	int numCity;
	int numRoad;
	std::vector<path> roads;
};
/* 出力値の形式 */
class OutputStruct {
public:
	long long pattern;
};
class AtCoderQuestion : public AtCoderQuestionBase<InputStruct, OutputStruct> {
public:
	AtCoderQuestion() {};
protected:
	InputStruct Input() final override;
	void Output(const OutputStruct& output, std::string* outStr = nullptr) final override;
	OutputStruct Solver(const InputStruct& input) final override;
private:
	const char* GetInputCase(uint8_t index) const final override;
	const char* GetOutputCase(uint8_t index) const final override;
	const int GetNumTestCase() const final override;
};
}
