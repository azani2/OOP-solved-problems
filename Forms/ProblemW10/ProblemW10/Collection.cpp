#include "Collection.h"
#pragma warning (disable: 4996)

void Collection::addLabel(Label& label) {
	this->data.push_back(new Label(label));
}

void Collection::addRadioButton(RadioButton& radioButton) {
	this->data.push_back(new RadioButton(radioButton));
}

void Collection::addTextBox(TextBox& textBox) {
	this->data.push_back(new TextBox(textBox));
}

const size_t Collection::getSize() const {
	return this->data.size();
}