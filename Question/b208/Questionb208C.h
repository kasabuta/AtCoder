#pragma once
#include "../../AtCoderQuestionBase.h"
static const char* contestName = "b208";
static const char* questionIndex = "C";
namespace Questionb208C {
/* 入力値の形式 */
class InputStruct {
public:
	int population;
	long long candy;
	std::vector<long long> ids;
};
/* 出力値の形式 */
class OutputStruct {
public:
	std::vector<long long> num;
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
