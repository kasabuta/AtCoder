#include "QuestionAtCoderBS10.h"
#include "../../Utility/Utility.h"
namespace QuestionAtCoderBS10 {
namespace {
	const char* INPUT_CASE[] = {
	R"(erasedream)",
	R"(dreameraser)",
	R"(dreamerer)",
	};
	const char* OUTPUT_CASE[] = {
	R"(YES)",
	R"(YES)",
	R"(NO)",
	};
	static_assert(SIZEOF(OUTPUT_CASE) == SIZEOF(INPUT_CASE), "num of OUTPUT_CASE is invalid.");
}	// end of anonymous namespace.
const char* AtCoderQuestion::GetInputCase(uint8_t index) const {
	if (index < SIZEOF(INPUT_CASE)) {
		return INPUT_CASE[index];
	}
	return "";
}
const char* AtCoderQuestion::GetOutputCase(uint8_t index) const {
	if (index < SIZEOF(OUTPUT_CASE)) {
		return OUTPUT_CASE[index];
	}
	return "";
}
const int AtCoderQuestion::GetNumTestCase() const {
	return SIZEOF(INPUT_CASE);
}

const char* texts[] = {
	"dream",
	"dreamer",
	"erase",
	"eraser",
};

bool DreamErase(std::string* str) {
	bool result = false;
	for (auto text : texts) {
		auto sub = str->substr(0, strlen(text));
		if (std::strcmp(text, sub.c_str()) == 0) {
			str->erase(0, strlen(text));
			if (str->empty()) {
				result = true;
			} else {
				result = DreamErase(str);
			}
			if (result) {
				return true;
			}
			str->insert(0, text);
		}
	}
	return false;
}

/* ‰ð–@ */
void AtCoderQuestion::Solver() {
	auto input = m_input.GetInputString();
	auto result = DreamErase(&input);
	m_output.OutputFormat("%s", result ? "YES" : "NO");
}
}
