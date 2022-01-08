#pragma once
#include "../../AtCoderQuestionBase.h"
static const char* contestName = "b200";
static const char* questionIndex = "E";
namespace Questionb200E {
class InputStruct {
public:
	int max;
	long long index;
};
class OutputStruct {
public:
	int i;
	int j;
	int k;
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
