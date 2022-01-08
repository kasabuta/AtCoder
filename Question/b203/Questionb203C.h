#pragma once
#include "../../AtCoderQuestionBase.h"
static const char* contestName = "b203";
static const char* questionIndex = "C";
namespace Questionb203C {
/* ���͒l�̌`�� */
class InputStruct {
public:
	long long numFriends;
	long long money;
	struct Friend {
		Friend() {};
		long long village;
		long long money;
		bool operator<(const Friend& right) const {
			return village < right.village;
		}

		bool operator>(const Friend& right) const {
			return village > right.village;
		}
	};
	std::vector<Friend> friends;
};
/* �o�͒l�̌`�� */
class OutputStruct {
public:
	long long village;
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
