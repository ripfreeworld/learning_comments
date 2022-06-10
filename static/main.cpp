#include <iostream>
#include <string>
using namespace std;
class Bank
{
    string name;
    int age;
    static double rate;
    static void InitRate(double _rate){rate = _rate;}
public:
    // static data member cannot be here in the constructor
    Bank(const string& _str, int _age):
    name(_str),
    age(_age)
    {

    }
    static double GetRate(){ return rate; }
    static void SetRate(double _rate);

};

// 'static' can only be specified inside the class definition
// here is forbidden
void Bank::SetRate(double _rate) {
    rate = _rate;
}

 // not allowed inside a function (e.g. main())
 // can access private here
 // static data members cannot be initialized inside the class, (however possible with constexpr)
 // but outside the class body, better the same file that contains the definitions of the class
 // the static data member may be defined only once
double Bank::rate = 0.1;

void func(){
    // local static object in a function (main function is also a function)
    // destroyed when the program terminates
    // initialized before the first execution, initialized only once
    // if no explicit initializer, value initialized => zero
    static int i_static = 1;
    i_static++;
    // do something

}

// file static (inherited from C)
// program declares global name as static to make it local to the current file
static int i_file_global = 12;
// congruent with file static
// Names defined in an unnamed namespace are in the same scope as the scope at which the namespace is defined
namespace {
    int i_file_global2 = 13;
}

int main() {
    for (int i = 0; i < 5; ++i) {
        func();
    }
    double rate_today = Bank::GetRate();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
