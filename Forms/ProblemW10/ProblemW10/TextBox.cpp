#include "TextBox.h"
#pragma warning (disable: 4996)

TextBox::TextBox(float _x, float _y, const char* _text) : ComponentBase(_x, _y) {
	length = strlen(_text);
	text = new char[length];
	strcpy(text, _text);
}

void TextBox::showDialog() {
	std::cout << "Enter x coordinates: ";
	std::cin >> this->x;
	std::cout << "Enter y coordinates: ";
	std::cin >> this->y;
	std::cout << "Enter text: ";
	char temp[1024] = "";
	std::cin >> temp;
	length = strlen(temp);
	text = new char[length];
	strcpy(this->text, temp);
}