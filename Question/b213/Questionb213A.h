#pragma once
#include "../../AtCoderQuestionBase.h"
static const char* contestName = "b213";
static const char* questionIndex = "A";
namespace Questionb213A {
/* ���͒l�̌`�� */
class InputStruct {
public:
	int A;
	int B;
};
/* �o�͒l�̌`�� */
class OutputStruct {
public:
	int C;
};
class AtCoderQuestion : public AtCoderQuestionBase<InputStruct, OutputStruct> {
public:
	AtCoderQuestion() {};
protected:
	InputStruct Input() final override;
	void Output(const OutputStruct& output) final override;
	OutputStruct Solver(const InputStruct& input) final override;
private:
	const char* GetInputCase(uint8_t index) const final override;
	const char* GetOutputCase(uint8_t index) const final override;
	const int GetNumTestCase() const final override;
};
}
