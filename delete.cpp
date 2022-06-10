#include <iostream>
using namespace std;

void modifyPointerValue(int* pi){
	*pi = 42;
}

int main(int argc, char const *argv[])
{
	int a = 5;
	int* pa = &a;

	modifyPointerValue(pa);
	cout << a << endl;
	return 0;
}