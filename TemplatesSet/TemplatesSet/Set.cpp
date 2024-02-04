#include "Set.h"


template <typename T>
Set<T> operator+(const Set<T>& set1, const Set<T>& set2) {
	Set<T> result(set1);
	size_t length = set2.getSize();
	for (size_t i = 0; i < length; i++)
		result.add(set2.data[i]);
	return result;
}

template <typename T>
bool operator<(const Set<T>& subset, const Set<T>& superset) {
	size_t length = subset.getSize();
	for (size_t i = 0; i < length; i++)
	{
		if (!superset.contains(subset.data[i]))
			return false;
	}
	return true;
}

int main() {
	Set<int> ints1;
	for (size_t i = 1; i < 10; i += 2)
		ints1.add(i);

	Set<int> ints2;
	for (size_t i = 2; i < 10; i += 2)
		ints2.add(i);

	std::cout << "Ints 1:\n";
	ints1.print();

	std::cout << "Ints 2:\n";
	ints2.print();

	Set<double> doubles;
	for (double i = 2.55; i < 15; i += 2)
		doubles.add(i);

	std::cout << "Doubles:\n";
	doubles.print();

	Set<int> ints3;
	ints3.add(2);
	ints3.add(4);

	std::cout << "Ints 3:\n";
	ints3.print();

	std::cout << "Ints 3 subset of Ints 2? : " << (ints3 < ints2) << std::endl;

	Set<int> combined = ints1 + ints2;
	std::cout << "Combined Ints 1 and Ints 2:\n";
	combined.print();
}