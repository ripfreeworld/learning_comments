#include <iostream>
class A {
public:
    void func();
};
class B {
    friend void A::func();
};
void func() {
    return;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
