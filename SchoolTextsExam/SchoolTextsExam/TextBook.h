#pragma once
#include "Poem.h"
#include "ArgumentText.h"
#include <fstream>

class TextBook {
private:
	Text** texts;
	size_t size;

	void free();
	void copy(const TextBook& other);

public:
	TextBook();
	TextBook(const size_t size);
	TextBook(const TextBook& other);
	TextBook& operator=(const TextBook& other);
	~TextBook();

	bool addText(Text* toAdd) const;

	friend std::ostream& operator<<(std::ostream& out, const TextBook& book);
	const char* operator[](size_t idx) const;
};

