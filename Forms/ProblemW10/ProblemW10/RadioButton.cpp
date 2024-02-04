#include "RadioButton.h"
#pragma warning (disable: 4996)

RadioButton::RadioButton(float _x, float _y, const char* _text) : ComponentBase(_x, _y), checked(false) {
	if (strlen(_text) > 16)
		throw std::exception("Invalid argument!");

	strcpy(text, _text);
}

void RadioButton::flip() {
	this->checked = !this->checked;
}

bool RadioButton::isOn() const {
	return checked;
}

void RadioButton::showDialog() {
	std::cout << "Enter x coordinates: ";
	std::cin >> this->x;
	std::cout << "Enter y coordinates: ";
	std::cin >> this->y;
	std::cout << "Enter text (<16 symbols): ";
	std::cin >> this->text;
	std::cout << "Checked (0/1): ";
	std::cin >> this->checked;
}