#pragma once
#include "../../AtCoderQuestionBase.h"
static const char* contestName = "b211";
static const char* questionIndex = "C";
namespace Questionb211C {
/* ���͒l�̌`�� */
class InputStruct {
public:
	std::string text;
};
/* �o�͒l�̌`�� */
class OutputStruct {
public:
	long long num;
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