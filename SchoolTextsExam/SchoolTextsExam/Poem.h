#pragma once
#pragma warning (disable: 4996)
#include "Text.h"

class Poem : public Text {
private:
    char** words;
    size_t size;

    void free() override;
    void copy(const Poem& other);

public:
    Poem();
    Poem(const char* content, const size_t size);
    Poem(const Poem& other);
    Poem& operator=(const Poem& other);
    ~Poem();
    
    Text* clone() const override;

    const char* print() const override;

    bool addKeyWord(const char* word) const;
};

