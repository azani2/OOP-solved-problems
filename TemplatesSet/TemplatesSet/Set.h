#pragma once
#include <iostream>

template <typename T>
class Set {
private:
	T* data;
	size_t size, capacity;

	void free();
	void copy(const Set<T>& other);
	void resize();

public:

	Set();
	Set(const Set<T>& other);
	Set<T>& operator=(const Set<T>& other);
	~Set();


	bool add(const T& toAdd);
	bool isEmpty();
	void print();
	bool contains(const T& toFind) const;
	const size_t getSize() const;
	 
	template <typename T>
	friend Set<T> operator+(const Set<T>& set1, const Set<T>& set2);
	template <typename T>
	friend bool operator<(const Set<T>& subset, const Set<T>& superset);
};

template <typename T>
void Set<T>::free() {
	delete[] data;
}

template <typename T>
void Set<T>::copy(const Set<T>& other) {
	this->capacity = other.capacity;
	this->size = other.size;
	data = new T[capacity];
	for (size_t i = 0; i < size; i++)
		data[i] = other.data[i];
}

template <typename T>
void Set<T>::resize() {
	capacity *= 2;
	T* temp = new T[capacity];
	for (size_t i = 0; i < size; i++)
		temp[i] = data[i];
	delete[] data;
	data = temp;
}

template <typename T>
Set<T>::Set() : size(0), capacity(8) {
	data = new T[capacity];
}

template <typename T>
Set<T>::Set(const Set<T>& other) {
	copy(other);
}

template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

template <typename T>
Set<T>::~Set() {
	free();
}

template <typename T>
bool Set<T>::add(const T& toAdd) {
	if (contains(toAdd))
		return false;
	if (size == capacity)
		resize();
	data[size] = toAdd;
	size++;
	return true;
}

template <typename T>
bool Set<T>::isEmpty() {
	return size == 0;
}

template <typename T>
void Set<T>::print() {
	for (size_t i = 0; i < size; i++)
		std::cout << data[i] << "\n";
}

template <typename T>
bool Set<T>::contains(const T& toFind) const {
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == toFind)
			return true;
	}
	return false;
}

template <typename T>
const size_t Set<T>::getSize() const {
	return size;
}
