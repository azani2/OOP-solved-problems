#pragma once
#pragma warning (disable: 4996)
#include <iostream>
#include <cstring>

class Text {
private:
	static int textsCount;
	int id;

protected:
	char* content;
	
	void copyBase(const Text& other);
	virtual void free();

public:
	Text();
	Text(const char* content);
	Text(const Text& other);
	Text& operator=(const Text& other);
	virtual ~Text();

	const char* getContent() const;
	virtual const char* print() const;

	virtual Text* clone() const = 0;
	static const int getNextId();
};

