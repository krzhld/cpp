#pragma once
#include <array>
#include <Windows.h>

#define FREQ 16
#define COLORSTEP 32

class Graphics {
public:
	Graphics();
	std::array<HPEN, FREQ / 2> getPens(void) { return this->pens; }
private:
	std::array<HPEN, FREQ / 2> pens;
};
