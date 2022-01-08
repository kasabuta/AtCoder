#pragma once
#include <cassert>
#include <cstdio>
#include <cstring>
#include <stdarg.h>
#include <string>
#include <vector>

#include "Utility/InputManager.h"
#include "Utility/OutputManager.h"

class AtCoderQuestionBase {
protected:
	AtCoderQuestionBase()
		: m_input()
		, m_output()
	{};

	virtual void Solver() = 0;

public :
	void Answer();
	bool Check();

private:
	virtual const char* GetInputCase(uint8_t index) const = 0;
	virtual const char* GetOutputCase(uint8_t index) const = 0;
	virtual const int GetNumTestCase() const = 0;

protected:
	InputManager m_input;
	OutputManager m_output;
};


