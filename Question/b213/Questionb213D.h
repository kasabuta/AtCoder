#pragma once
#include "../../AtCoderQuestionBase.h"
static const char* contestName = "b213";
static const char* questionIndex = "D";
namespace Questionb213D {
	struct Road {
		int from;
		int to;
	};

/* ���͒l�̌`�� */
class InputStruct {
public:
	int numCity;
	std::vector<Road> roads;
};
/* �o�͒l�̌`�� */
class OutputStruct {
public:
	std::vector<int> cities;
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
