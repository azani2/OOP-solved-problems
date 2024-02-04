#include <iostream>

template <typename T, size_t size> 
class MyArray {
	T* data;
public:
	MyArray() {
		data = new T[size];
	}

	MyArray(const MyArray& other) {
		data = new T[size];
		for (size_t idx = 0; idx < size; ++idx) {
			data[idx] = other.data[idx];
		}
	}

	MyArray& operator=(const MyArray& other) {
		if (this != &other) {
			for (size_t idx = 0; idx < size; ++idx) {
				data[idx] = other.data[idx];
			}
		}
		return *this;
	}

	~MyArray() {
		delete[] data;
	}

	const T& operator[](const size_t& index) const {
		return data[index];
	}

	T& operator[](const size_t& index) {
		return data[index];
	}

};

int main() {

	MyArray<int, 10> size_ten_array;
	MyArray<int, 20> size_twenty_array;
	MyArray<float, 30> size_thirty_array;
}