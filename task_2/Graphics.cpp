#include "Graphics.h"

Graphics::Graphics(void) {
	for (int i = 0; i < FREQ / 2; i++) {
		this->pens[i] = CreatePen(PS_SOLID, 5, RGB(COLORSTEP * i, COLORSTEP * i, COLORSTEP * i));
	}
}
