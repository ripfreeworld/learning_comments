#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int a = 5;
	int& b = a;

	cout << &a << &b;
	return 0;
}