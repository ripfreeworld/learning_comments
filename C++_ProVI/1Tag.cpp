#include <iostream>
/*
	-Pointer, Referenzen, Values
	-Pointer und Array
	-call by value / reference und by address
	-return by value / reference und by address

	Memory Management:
		- Memory Layout (Welche Bestandteile)
				- Code/ Text
				- Static
				- Heap ( Free Store)

				- Stack
*/


int main() {
	int* arry = new int[10];
	arry[0] = {100};
	arry[1] = {101};
	arry[2] = {102};

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << arry[i] << std::endl;
	}
	delete[] arry;
	return 0;
}

auto print_array10(std::ostream& os, int* a) {
	for (size_t i = 0; i < 10; i++)
	{
		os << a[i] << std::endl;
	}
}

auto print_array(std::ostream& os, int* a, int n) {
	for (int i = 0; i < n; i++)
	{
		os << a[i] << std::endl;
	}
}