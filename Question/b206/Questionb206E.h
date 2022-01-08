#pragma once
#include "../../AtCoderQuestionBase.h"
static const char* contestName = "b206";
static const char* questionIndex = "E";
namespace Questionb206E {
/* ���͒l�̌`�� */
class InputStruct {
public:
};
/* �o�͒l�̌`�� */
class OutputStruct {
public:
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