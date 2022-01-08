#pragma once
#include "../../AtCoderQuestionBase.h"

static const char* contestName = "TITLE";
static const char* questionIndex = "QINDEX";

namespace QuestionTITLEQINDEX {
class AtCoderQuestion : public AtCoderQuestionBase {
public:
	AtCoderQuestion() {};

protected:
	void Solver() final override;

private:
	const char* GetInputCase(uint8_t index) const final override;
	const char* GetOutputCase(uint8_t index) const final override;
	const int GetNumTestCase() const final override;
};
}
