#pragma once
#include <iostream>
class A
{
private:
    int var1;   
    int var2;

public:
    A(int a, int b) ;
    int add(int a, int b) const;
    int getSum() const;
    void setVar1(int a);
    ~A();
};




