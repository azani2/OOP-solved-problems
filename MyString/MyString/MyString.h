#ifndef MYSTRING_H
#define MYSTRING_H

class MyString {
private:
    char* content;
    unsigned size;

    void copy(const MyString&);
    void erase();

public:
    MyString();
    MyString(const char*);

    MyString(const MyString&);
    MyString& operator=(const MyString&);
    ~MyString();

    int length();
    char& at(unsigned);
    int find(char, unsigned);
    bool empty() const;
    MyString substr(unsigned, unsigned);
    void append(const MyString&);
    void print();
};

#endif#pragma once
