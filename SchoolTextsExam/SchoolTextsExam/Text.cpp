#include "Text.h"

int Text::textsCount = 0;

void Text::copyBase(const Text& other) {
	size_t length = strlen(other.content);
	content = new char[length];
	strcpy(content, other.content);
}

void Text::free() {
	delete[] content;
}

Text::Text() {
	content = new char[1]{ "" };
}

Text::Text(const char* _content) {
	id = ++textsCount;
	size_t length = strlen(_content);
	content = new char[length];
	strcpy(content, _content);
}

Text::Text(const Text& other) {
	copyBase(other);
}

Text& Text::operator=(const Text& other) {
	if (this != &other)
	{
		free();
		copyBase(other);
	}
	return *this;
}

Text::~Text() {
	free();
}

const char* Text::getContent() const {
	return content;
}

const char* Text::print() const {
	return content;
}

const int Text::getNextId() {
	return textsCount + 1;
}
