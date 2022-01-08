#include "Utility/MakeSubmitFile.h"
#include "Question/b213/Questionb213C.h"

namespace {
const bool IS_CHECK = true;
}

int main() {
	Questionb213C::AtCoderQuestion question;
	if (IS_CHECK) {
		question.Check();
		MakeSubmitFile(contestName, questionIndex);
	} else {
		question.Answer();
	}
	return 0;
}
