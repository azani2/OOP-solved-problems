#pragma once
#include "ComponentBase.h"

class RadioButton : public ComponentBase {
private:
	char text[16];
	bool checked;

public:
	RadioButton() = default;
	RadioButton(float _x, float _y, const char* _text);
	void flip();
	bool isOn() const;
	void showDialog() override;
};

