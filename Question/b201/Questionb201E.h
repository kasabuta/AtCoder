#pragma once
#include "../../AtCoderQuestionBase.h"
static const char* contestName = "b201";
static const char* questionIndex = "E";
namespace Questionb201E {
/* 入力値の形式 */
class InputStruct {
public:
};
/* 出力値の形式 */
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
