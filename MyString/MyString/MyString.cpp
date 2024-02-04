#include "MyString.h"
#include <iostream>
#include <cstring>

void MyString::copy(const MyString& other)
{
	size = other.size;
	if (other.empty())
		content = nullptr;
	else
	{
		content = new char[size];
		for (size_t i = 0; i < size; i++)
			content[i] = other.content[i];
	}
}

void MyString::erase() {
	delete[] content;
}

MyString::MyString() : content(nullptr), size(0) 
{}

MyString::MyString(const char* str)
{
	size = strlen(str);
	if (size == 0)
		content = nullptr;
	else
	{
		content = new char[size];
		for (size_t i = 0; i < size; i++)
			content[i] = str[i];
	}
}

MyString::MyString(const MyString& other)
{
	copy(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

MyString::~MyString()
{
	erase();
}

int MyString::length()
{
	return size;
}

char& MyString::at(unsigned idx)
{
	if (idx >= size)
		throw std::exception("Invalid index");
	return content[idx];
}

int MyString::find(char c, unsigned startIdx)
{
	if (startIdx >= size)
		throw std::exception("Invalid start index");
	for (size_t i = startIdx; i < size; i++)
		if (content[i] == c)
			return i;
	return -1;
}

bool MyString::empty() const
{
	return size == 0;
}

MyString MyString::substr(unsigned pos, unsigned length)
{
	if (pos >= size)
		throw std::exception("Invalid start index");
	if (length == 0)
		return MyString();

	MyString res;
	if (pos + length > size)
		res.size = size - pos;
	else
		res.size = length;

	res.content = new char[res.size];
	for (size_t i = pos; i < pos + length && i < size; i++)
		res.content[i - pos] = content[i];
	
}

void MyString::append(const MyString& other)
{
	if (empty())
	{
		*this = other;
		return;
	}

	MyString res;
	res.size = size + other.size;
	res.content = new char[size];

	for (size_t i = 0; i < size; i++)
		res.content[i] = content[i];

	for (size_t i = 0; i < other.size; i++)
		res.content[i + size] = other.content[i];

	*this = res;
}

void MyString::print()
{
	for (size_t i = 0; i < size; i++)
		std::cout << content[i];
}
