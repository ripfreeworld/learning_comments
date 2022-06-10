#include <iostream>
using std::cout;
using std::endl;

class Shape {
public:
    Shape() {
        cout << "Shape object created" << endl;
    }
    ~Shape() {
        cout << "Shape object destroyed" << endl;
    }
};

class Circle : public Shape {
public:
    Circle() {
        cout << "Circle object created" << endl;
    }
    ~Circle() {
        cout << "Circle object destroyed" << endl;
    }
};


int main() {
    Circle obj_circle;
    Circle* obj_circle_new = new Circle();
    delete obj_circle_new;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
