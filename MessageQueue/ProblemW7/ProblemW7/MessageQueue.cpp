#include "MessageQueue.h"
#include <iostream>
#include <fstream>
#pragma warning (disable: 4996)

MessageQueue::MessageQueue(const char* _filePath, mode _mode) {
	strcpy(filePath, _filePath);
	if (_mode == mode::open)
		file.open(_filePath, std::ios::in);
	else
		file.open(_filePath, std::ios::trunc);
}

void MessageQueue::open(const char* _filePath, mode _mode) {
	strcpy(filePath, _filePath);
	if (_mode == mode::open)
		file.open(_filePath, std::ios::app);
	else
		file.open(_filePath, std::ios::trunc);
}

size_t MessageQueue::read(char*& msg) {//ako ima nqkoi v queue go mahame
	if (this->queue.empty())
	{
		sync();
		return 0;
	}
	int lastIdx = this->queue.size() - 1;
	msg = new char[1024];
	strcpy(msg, this->queue[lastIdx]);
	this->queue.pop_back();
	return sizeof(msg);
}

void MessageQueue::sync() {//vs ot file -> queue
	if (!file.is_open())
	{
		std::cout << "Error opening file for reading!\n";
		return;
	}

	while (!file.eof())
	{
		char buff[1024];
		file.getline(buff, 1024);
		char* newMsg = new char[strlen(buff)];
		strcpy(newMsg, buff);
		this->queue.push_back(newMsg);
	}
	std::cout << "All lines read!\n";
}

void MessageQueue::write(const char* msg, size_t size) {
	char* toPush = new char[size];
	strcpy(toPush, msg);
	this->queue.push_back(toPush);
}

const size_t MessageQueue::getLength() const {
	return this->queue.size();
}