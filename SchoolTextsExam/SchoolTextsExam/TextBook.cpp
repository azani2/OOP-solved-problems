#include "TextBook.h"

void TextBook::free() {
	for (size_t i = 0; i < size; i++)
	{
		if (texts[i] != nullptr)
			delete texts[i];
	}
	delete[] texts;
}

void TextBook::copy(const TextBook& other) {
	size = other.size;
	texts = new Text * [size];
	for (size_t i = 0; i < size; i++)
		texts[i] = other.texts[i]->clone();
}

TextBook::TextBook() : size(1) {
	texts = new Text * [1] { nullptr };
}

TextBook::TextBook(const size_t size) : size(size) {
	texts = new Text * [size] { nullptr };
}

TextBook::TextBook(const TextBook& other) {
	copy(other);
}

TextBook& TextBook::operator=(const TextBook& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

TextBook::~TextBook() {
	free();
}

bool TextBook::addText(Text* toAdd) const {
	for (size_t i = 0; i < size; i++)
	{
		if (texts[i] == nullptr)
		{
			texts[i] = toAdd;
			return true;
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const TextBook& book) {
	for (size_t i = 0; i < book.size; i++)
		if (book.texts[i] != nullptr)
			out << book.texts[i]->print() << "\n----\n";
	return out;
}

const char* TextBook::operator[](size_t idx) const {
	if (idx >= size)
		throw std::exception("Index out of bounds!");

	if (texts[idx] == nullptr)
		throw std::exception("Element was nullptr!");

	std::ofstream fout("textsData.txt", std::ios::app | std::ios::_Nocreate);
	if (!fout.is_open())
		throw std::exception("Error opening file for writing!");

	fout << texts[idx]->print() << "\n----\n";
	fout.flush();
	fout.close();
	return texts[idx]->print();
}
