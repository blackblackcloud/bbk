#include "Mypointer.h"




template<typename T>
T add(T a, T b) {
    return a + b;
}
int main() {
     int (A::*funcPtr)(int, int) const ; // 定义一个函数指针，指向 add 函数
     funcPtr = &A::add; // 将函数指针指向 A 类的 add 函数
    A obj(3, 4); // 创建 A 类的对象 
    int result = (obj.*funcPtr)(3, 4); // 通过函数指针调用 add 函数
    std::cout << "结果: " << result << std::endl; // 输出结果
    return 0;
    
}