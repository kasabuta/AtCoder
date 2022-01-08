#pragma once
#include "../../AtCoderQuestionBase.h"
static const char* contestName = "198";
static const char* questionIndex = "F";
namespace Question198F {
class InputStruct {
public:
	int numSnack;
};
class OutputStruct {
public:
	int numPattern;
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
