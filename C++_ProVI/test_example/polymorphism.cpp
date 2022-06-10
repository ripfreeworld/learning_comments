#include<iostream>
using namespace std;

// Polymorphism
class Animal
{
public:
	Animal(){}
	~Animal(){}
	virtual void some_func() = 0;	
};
class Dog : public Animal
{
public:
	Dog(){}
	~Dog(){}
	virtual void some_func() override{
		return;
	}	
};

int main(int argc, char const *argv[])
{
	// use Animal pointer to access Dog or any other subclass objects
	Animal* pAnim = new Dog(); // heap
	return 0;
}
