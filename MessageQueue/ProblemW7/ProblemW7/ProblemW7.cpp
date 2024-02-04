#include <iostream>
#include <fstream>
#include <cstring>
#include <chrono>
#include <thread>
#pragma warning (disable: 4996)
#include "MessageQueue.h"

template<typename T>
class MyVector {
private:
	T* data;
	size_t size;
	size_t capacity;

	void resize();
	void copy(const MyVector<T>& other);
	void free();

	void shift_left(const size_t start);
	void shift_right(const size_t start);

public:
	MyVector<T>(size_t _capacity = 16);
	MyVector<T>(const MyVector<T>& other);
	~MyVector<T>();
	MyVector<T>& operator=(const MyVector<T>& other);

	size_t getSize() const;
	void insertAt(size_t idx, const T& toInsert);
	T remove(size_t idx);

	void push_back(const T& toPush);
	T pop_back();

	void push_front(const T& toPush);
	T pop_front();

	T& operator[](size_t idx);
	const T& operator[](size_t idx) const;
};

template<typename T>
void MyVector<T>::copy(const MyVector<T>& other) {
	this->size = other.size;
	this->capacity = other.capacity;
	this->data = new T[this->capacity];
	for (size_t i = 0; i < this->size; i++)
		this->data[i] = other.data[i];
}

template<typename T>
MyVector<T>::MyVector(const size_t _capacity) : capacity(_capacity) {
	this->size = 0;
	this->data = new T[this->capacity];
}

template<typename T>
MyVector<T>::MyVector(const MyVector<T>& other) {
	this->copy(other);
}

template<typename T>
void MyVector<T>::resize() {
	this->capacity *= 2;
	T* temp = new T[capacity];
	for (size_t i = 0; i < size; i++)
		temp[i] = this->data[i];
	delete[] data;
	data = temp;
}

template<typename T>
void MyVector<T>::free() {
	this->size = 0;
	this->capacity = 0;
	delete[] this->data;//??
}

template<typename T>
T& MyVector<T>::operator[](size_t idx) {
	return this->data[idx];
}

template<typename T>
const T& MyVector<T>::operator[](size_t idx) const {
	return this->data[idx];
}

template<typename T>
MyVector<T>::~MyVector<T>() {
	free();
}

template<typename T>
void MyVector<T>::shift_left(size_t start) {
	this->size--;

	for (start; start < this->size; start++)
		this->data[start] = this->data[start + 1];
}

template<typename T>
void MyVector<T>::shift_right(size_t start) {
	this->size++;

	for (size_t i = this->size; i > start; i--)
		this->data[i] = this->data[i - 1];
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

template<typename T>
size_t MyVector<T>::getSize() const {
	return this->size;
}

template<typename T>
void MyVector<T>::insertAt(size_t idx, const T& toInsert) {
	if (idx > this->size)
		throw std::exception("Index outof bounds!");

	if (this->size == this->capacity)
		resize();

	shift_right(idx);
	this->data[idx] = toInsert;
}

template<typename T>
T MyVector<T>::remove(size_t idx) {
	if (idx > this->size)
		throw std::exception("Index out of bounds!");

	T removed = this->data[idx];
	shift_left(idx);
	return removed;
}

template<typename T>
void MyVector<T>::push_back(const T& toPush) {
	insertAt(this->size, toPush);
}

template<typename T>
void MyVector<T>::push_front(const T& toPush) {
	insertAt(0, toPush);
}

template<typename T>
T MyVector<T>::pop_back() {
	if (this->size < 1)
		throw std::exception("Index out of bounds!");

	return remove(this->size - 1);
}

template<typename T>
T MyVector<T>::pop_front() {
	if (this->size < 1)
		throw std::exception("Index out of bounds!");

	return remove(0);
}

int main()
{
	{/*
		MyVector<int> vecty(16);
		for (size_t i = 0; i < 18; i++)
			vecty.push_back(i + 1);

		std::cout << "vecty's size: " << vecty.getSize() << std::endl;
		for (size_t i = 0; i < vecty.getSize(); i++)
			std::cout << "vecty[" << i << "] : " << vecty[i] << std::endl;

		std::cout << "\npop back: " << vecty.pop_back() << std::endl;
		std::cout << "pop front: " << vecty.pop_front() << std::endl;
		std::cout << "pop back and push front" << std::endl;
		vecty.push_front(vecty.pop_back());

		std::cout << "\nvecty's size: " << vecty.getSize() << std::endl;
		for (size_t i = 0; i < vecty.getSize(); i++)
			std::cout << "vecty[" << i << "] : " << vecty[i] << std::endl;
		*/
		std::cout << "\n:))\n";
	}

	//message queue (poveche stek zashtoto e sus std::vector)
	{
		MessageQueue queue1("test.txt", mode::open);
		queue1.sync();
		size_t qLength = queue1.getLength();
		for (size_t i = 0; i < qLength; i++)
		{
			char* line;
			queue1.read(line);
			std::cout << line << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		

	}
}