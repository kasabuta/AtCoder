#pragma once
#include "../../AtCoderQuestionBase.h"
static const char* contestName = "AtCoderBS";
static const char* questionIndex = "6";
namespace QuestionAtCoderBS6 {
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
