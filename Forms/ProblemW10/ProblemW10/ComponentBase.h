#pragma once
#include <iostream>

class ComponentBase
{
protected:
	float x;
	float y;

public:
	ComponentBase() = default;
	ComponentBase(const float _x, const float _y);
	void move(float dx, float dy);
	virtual void showDialog() = 0;
	virtual ~ComponentBase() = default;
};

