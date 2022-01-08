#pragma once
#include "../../AtCoderQuestionBase.h"
static const char* contestName = "b200";
static const char* questionIndex = "C";
namespace Questionb200C {
class InputStruct {
public:
	int num;
	std::vector<long long> array;
};
class OutputStruct {
public:
	long long count;
};
class AtCoderQuestion : public AtCoderQuestionBase<InputStruct, OutputStruct> {
public:
	AtCoderQuestion();
protected:
	InputStruct Input() final override;
	void Output(const OutputStruct& output, std::string* outStr = nullptr) final override;
	OutputStruct Solver(const InputStruct& input) final override;
private:
	const char* GetInputCase(uint8_t index) const override;
	const char* GetOutputCase(uint8_t index) const override;
};
}
