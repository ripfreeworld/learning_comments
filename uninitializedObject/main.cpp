#include <iostream>

class PRE_A{
protected:
    int i;
};
class A{
    void func(PRE_A a){
        a.i = 0;
    }
};

int main() {
    PRE_A a{};
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
