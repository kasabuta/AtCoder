#pragma once
#include "../../AtCoderQuestionBase.h"
static const char* contestName = "198";
static const char* questionIndex = "E";
namespace Question198E {
struct Edge {
	int start;
	int end;
};
class InputStruct {
public:
	int sizeTree;
	std::vector<int> colors;
	std::vector<Edge> edges;
};
class OutputStruct {
public:
	std::vector<int> nodes;
};
class AtCoderQuestion : public AtCoderQuestionBase<InputStruct, OutputStruct> {
public:
	AtCoderQuestion();
protected:
	InputStruct Input() final override;
	void Output(const OutputStruct& output, std::string* outStr = nullptr) final override;
	OutputStruct Solver(const InputStruct& input) final override;
private:
	const char* GetInputCase(uint8_t index) const override;
	const char* GetOutputCase(uint8_t index) const override;
};
}
