#pragma once
#include "../../AtCoderQuestionBase.h"
static const char* contestName = "b234";
static const char* questionIndex = "G";
namespace Questionb234G {
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
