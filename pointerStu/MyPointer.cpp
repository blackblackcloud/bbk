#include "MyPointer.h"
int add(int a, int b) {
    return a + b;
}   
int main() {
    int (*funcPtr)(int, int) = add; // 定义一个函数指针，指向 add 函数
    int result = funcPtr(3, 4); // 通过函数指针调用 add 函数
    std::cout << "结果: " << result << std::endl; // 输出结果
    return 0;
    
}