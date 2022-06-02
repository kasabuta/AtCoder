#include "Utility/MakeSubmitFile.h"
//#include "Question/Typical/QuestionTypical51.h"
#include "Question/b251/Questionb251D.h"

namespace {
const bool IS_CHECK = true;
const bool WITHOUT_CHECK = true;
}

int main() {
	Questionb251D::AtCoderQuestion question;
	if (IS_CHECK) {
		if (WITHOUT_CHECK || question.Check()) {
			MakeSubmitFile(contestName, questionIndex);
		}
	} else {
		question.Answer();
	}
	return 0;
}
