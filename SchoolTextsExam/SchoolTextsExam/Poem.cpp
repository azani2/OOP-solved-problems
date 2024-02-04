#include "Poem.h"

void Poem::free() {
	for (size_t i = 0; i < size; i++)
		delete[] words[i];
	delete[] words;
}

void Poem::copy(const Poem& other) {
	copyBase(other);
	size = other.size;
	words = new char* [size];
	for (size_t i = 0; i < size; i++)
	{
		words[i] = new char[16];
		strcpy(words[i], other.words[i]);
	}
}

Poem::Poem() : Text() {
	size = 1;
	words = new char* [1];
	words[0] = nullptr;
}

Poem::Poem(const char* content, const size_t size) : Text(content), size(size) {
	words = new char* [size];
	for (size_t i = 0; i < size; i++)
		words[i] = nullptr;
}

Poem::Poem(const Poem& other) {
	copy(other);
}

Poem& Poem::operator=(const Poem& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Poem::~Poem() {
	free();
}

Text* Poem::clone() const {
	return new Poem(*this);
}

const char* Poem::print() const {
	size_t expected = strlen(getContent()) + 17 * size + 14;
	char* res = new char[expected];
	strcpy(res, "Key:\n");
	strcat(res, getContent());
	strcat(res, "\nKey:\n");
	for (size_t i = 0; i < size; i++)
	{
		if (words[i] != nullptr)
		{
			strcat(res, words[i]);
			strcat(res, "\n");
		}
	}
	strcat(res, "\0");
	size_t length = strlen(res);
	if (length < expected)
	{
		char* temp = new char[length + 1];
		strcpy(temp, res);
		delete[] res;
		return temp;
	}
	return res;
}

bool Poem::addKeyWord(const char* word) const {
	for (size_t i = 0; i < size; i++)
	{
		if (words[i] == nullptr)
		{
			words[i] = new char[16];
			strcpy(words[i], word);
			return true;
		}
	}
	return false;
}
