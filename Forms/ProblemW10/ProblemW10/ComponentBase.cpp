#include "ComponentBase.h"
#pragma warning (disable: 4996)

ComponentBase::ComponentBase(const float _x, const float _y) : x(_x), y(_y) {};

void ComponentBase::move(float dx, float dy) {
	x += dx;
	y += dy;
}