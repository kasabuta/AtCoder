#pragma once
#include "../../AtCoderQuestionBase.h"
static const char* contestName = "b203";
static const char* questionIndex = "A";
namespace Questionb203A {
/* ���͒l�̌`�� */
class InputStruct {
public:
	int a;
	int b;
	int c;
};
/* �o�͒l�̌`�� */
class OutputStruct {
public:
	int result;
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
