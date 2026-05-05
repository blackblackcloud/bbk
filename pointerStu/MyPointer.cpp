#include "MyPointer.h"
int add(int a, int b) {
    return a + b;
}   
A::A(int a, int b) : var1(a), var2(b) {}
A::~A() {
    std::cout << "A对象被销毁" << std::endl;
}
int A::getSum() const {
    return var1 + var2;
}
void A::setVar1(int a) {
    this->var1 = a;
}
int A::add(int a, int b) const {
    return a + b;
}