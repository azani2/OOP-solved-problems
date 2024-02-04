#pragma once
#include <iostream>
#include "ComponentBase.h"

class Label : public ComponentBase {
private:
	char text[16];
public:
	Label() = default;
	Label(float _x, float _y, const char* _text);
	void showDialog() override;
};

