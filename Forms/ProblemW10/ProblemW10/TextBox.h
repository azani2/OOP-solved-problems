#pragma once
#include "ComponentBase.h"


class TextBox : public ComponentBase {
private:
	char* text;
	size_t length;

public:
	TextBox() = default;
	TextBox(float _x, float _y, const char* _text);
	void showDialog() override;
};

