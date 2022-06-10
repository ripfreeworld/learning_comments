#include <iostream>

class Animal
{
public:
    virtual void MakeSomeSound() = 0;
};

class Duck : public Animal
{
public:
    void MakeSomeSound() override{
        std::cout << "Gua Gua" << std::endl;
    }
};

class Dog : public Animal
{
public:
    void MakeSomeSound() override{
        std::cout << "Wang Wang" << std::endl;
    }
};
int main() {
    Duck a_duck;
    Dog a_dog;
    a_duck.MakeSomeSound();
    a_dog.MakeSomeSound();

    Animal* ptr_animal;
    ptr_animal = &a_duck;
    ptr_animal->MakeSomeSound();

    return 0;
}
