#pragma once
#include "../../AtCoderQuestionBase.h"
static const char* contestName = "b213";
static const char* questionIndex = "C";
namespace Questionb213C {
struct Card {
	long long height;
	long long width;
};
/* 入力値の形式 */
class InputStruct {
public:
	long long height;
	long long width;
	int enableNum;
	std::vector<long long> heights;
	std::vector<long long> widths;
};
/* 出力値の形式 */
class OutputStruct {
public:
	std::vector<Card> cards;
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
