#include "Utility/MakeSubmitFile.h"
#include "Question/AtCoderBS/QuestionAtCoderBS11.h"

namespace {
const bool IS_CHECK = true;
const bool WITHOUT_CHECK = false;
}

int main() {
	QuestionAtCoderBS11::AtCoderQuestion question;
	if (IS_CHECK) {
		if (WITHOUT_CHECK || question.Check()) {
			MakeSubmitFile(contestName, questionIndex);
		}
	} else {
		question.Answer();
	}
	return 0;
}
