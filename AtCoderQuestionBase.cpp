#include "AtCoderQuestionBase.h"

void AtCoderQuestionBase::Answer() {
	m_input.SetCheckMode(false);

	Solver();
	m_output.Print();
}

bool AtCoderQuestionBase::Check() {
	m_input.SetCheckMode(true);

	bool checkResult = true;
	auto numTestCase = GetNumTestCase();
	for (int i = 0; i < numTestCase; i++) {
		m_input.SetupInputCase(GetInputCase(i));
		m_output.Reset();
		Solver();

		printf("[ Case %d ]\n", i + 1);
		printf("------    my output     ------\n");

		m_output.Print();
		printf("\n");

		if (strcmp(m_output.GetOutput().c_str(), GetOutputCase(i)) == 0) {
			printf("OK\n\n");
		} else {
			checkResult = false;
			printf("------ test case output ------\n");
			printf("%s\n", GetOutputCase(i));
			printf("Case %d is Failed.\n\n", i + 1);
		}
	}

	if (checkResult) {
		printf("***** Check Completed. *****\n");
	} else {
		printf("*****  Check Failed.   *****\n");
	}

	return checkResult;
}