#pragma once
#include "Text.h"

template <typename T>
class ArgumentText : public Text {
private:
	size_t lengths[4];
	T hidden;

	bool init(size_t l1, size_t l2, size_t l3, size_t l4);

public:
	ArgumentText(const char* content, size_t l1, size_t l2, size_t l3, size_t l4, const T& _hidden);
	ArgumentText(const ArgumentText& other);
	ArgumentText<T>& operator=(const ArgumentText& other);
	~ArgumentText() = default;

	Text* clone() const;
	const char* print() const override;
};

template <typename T>
bool ArgumentText<T>::init(size_t l1, size_t l2, size_t l3, size_t l4) {
	int sum = l1 + l2 + l3 + l4;
	return sum == strlen(this->content);
}


template <typename T>
ArgumentText<T>::ArgumentText(const char* content, size_t l1, size_t l2, size_t l3, size_t l4, const T& _hidden) : Text(content) {
	if (!init(l1, l2, l3, l4))
		throw std::exception("Index out of bounds!");
	lengths[0] = l1;
	lengths[1] = l2;
	lengths[2] = l3;
	lengths[3] = l4;
	hidden = _hidden;
}

template <typename T>
ArgumentText<T>::ArgumentText(const ArgumentText& other) : Text(other) {
	for (size_t i = 0; i < 4; i++)
		lengths[i] = other.lengths[i];
	hidden = other.hidden;
}

template <typename T>
ArgumentText<T>& ArgumentText<T>::operator=(const ArgumentText& other) {
	if (this != &other)
	{
		Text::operator=(other);
		for (size_t i = 0; i < 4; i++)
			lengths[i] = other.lengths[i];
		hidden = other.hidden;
	}
	return *this;
}

template<typename T>
Text* ArgumentText<T>::clone() const {
	return new ArgumentText<T>(*this);
}

template<typename T>
const char* ArgumentText<T>::print() const {
	size_t expected = strlen(getContent()) + 50;
	char* res = new char[expected];

	strcpy(res, "Argument text:\nPart 1:\n");
	for (size_t i = 0; i < lengths[0]; i++)
	{
		strcat(res, (const char*)(getContent()[i]));
	}
	strcat(res, "\n");

	strcpy(res, "Part 2:\n");
	for (size_t i = lengths[0]; i < lengths[1]; i++)
	{
		strcat(res, (const char*)getContent()[i]);
	}
	strcat(res, "\n");

	strcpy(res, "Part 3:\n");
	for (size_t i = lengths[1]; i < lengths[2]; i++)
	{
		strcat(res, (const char*)getContent()[i]);
	}
	strcat(res, "\n");

	strcpy(res, "Part 4:\n");
	for (size_t i = lengths[2]; i < lengths[3]; i++)
	{
		strcat(res, (const char*)getContent()[i]);
	}
	strcat(res, "\n");
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

