#pragma once
#include "../../AtCoderQuestionBase.h"
static const char* contestName = "b203";
static const char* questionIndex = "B";
namespace Questionb203B {
/* ���͒l�̌`�� */
class InputStruct {
public:
	int floor;
	int room;
};
/* �o�͒l�̌`�� */
class OutputStruct {
public:
	int sum;
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
