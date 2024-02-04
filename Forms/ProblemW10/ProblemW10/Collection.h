#pragma once
#include "Label.h"
#include "RadioButton.h"
#include "TextBox.h"
#include <vector>

class Collection {
private:
	std::vector<ComponentBase*> data;

public:
	void addLabel(Label& label);
	void addRadioButton(RadioButton& radioButton);
	void addTextBox(TextBox& textBox);
	const size_t getSize() const;
};

