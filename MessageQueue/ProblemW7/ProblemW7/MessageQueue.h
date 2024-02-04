#pragma once
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#pragma warning (disable: 4996)

enum class mode {
	open,
	create
};

class MessageQueue {
private:
	std::vector<char*> queue;
	std::fstream file;
	char filePath[128];

public:
	MessageQueue(const char* _filePath, mode _mode);
	void open(const char* _filePath, mode _mode);
	size_t read(char*& msg);
	void write(const char* msg, size_t size);
	void sync();
	const size_t getLength() const;
};
