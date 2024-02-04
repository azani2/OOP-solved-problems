#include "Label.h"
#pragma warning (disable: 4996)

Label::Label(float _x, float _y, const char* _text) : ComponentBase(_x, _y) {
	if (strlen(_text) > 16)
		throw std::exception("Invalid argument!");
	
	strcpy(text, _text);
}

void Label::showDialog() {
	std::cout << "Enter x coordinates: ";
	std::cin >> this->x;
	std::cout << "Enter y coordinates: ";
	std::cin >> this->y;
	std::cout << "Enter text (<16 symbols): ";
	std::cin >> this->text;
}