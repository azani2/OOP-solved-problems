#include <iostream>
#include "Collection.h"
#pragma warning (disable: 4996)

int main() {
	Collection forms;
	Label l1, l2;
	l1.showDialog();
	l2.showDialog();
	RadioButton r1;
	r1.showDialog();
	r1.flip();
	std::cout << "Flip\nIs on: " << r1.isOn() << std::endl;
	TextBox t1;
	t1.showDialog();
	forms.addLabel(l1);
	forms.addLabel(l2);
	forms.addRadioButton(r1);
	forms.addTextBox(t1);
	std::cout << "collection size: " << forms.getSize() << std::endl;
}