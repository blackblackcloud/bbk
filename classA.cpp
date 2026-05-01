#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    本文件用多个小案例演示 C++ 中“类”的常见知识点：
    1. 类和对象
    2. 成员变量和成员函数
    3. public / private 封装
    4. 构造函数
    5. this 指针
    6. 静态成员 static
    7. 类的组合
    8. 继承和多态
*/

// 案例 1：最基础的类
class Student {
private:
    // private 表示只能在类的内部访问，外部不能直接修改
    string name;
    int age;
    double score;

public:
    // 构造函数：创建对象时自动调用，用来初始化对象
    Student(string studentName, int studentAge, double studentScore) {
        name = studentName;
        age = studentAge;
        score = studentScore;
    }

    // 成员函数：属于这个类的函数
    void showInfo() {
        cout << "姓名: " << name
             << ", 年龄: " << age
             << ", 成绩: " << score << endl;
    }

    // setter：通过函数控制外部对 private 数据的修改
    void setScore(double newScore) {
        if (newScore >= 0 && newScore <= 100) {
            score = newScore;
        } else {
            cout << "成绩必须在 0 到 100 之间" << endl;
        }
    }

    // getter：通过函数安全地读取 private 数据
    double getScore() {
        return score;
    }
};

// 案例 2：使用 this 指针
class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double width, double height) {
        // this 指向当前对象
        // 当参数名和成员变量名相同时，可以用 this-> 区分
        this->width = width;
        this->height = height;
    }

    double getArea() {
        return width * height;
    }

    double getPerimeter() {
        return 2 * (width + height);
    }
};

// 案例 3：静态成员
class BankAccount {
private:
    string owner;
    double balance;

public:
    // static 静态成员属于类本身，不属于某一个对象
    static int accountCount;

    BankAccount(string owner, double balance) {
        this->owner = owner;
        this->balance = balance;
        accountCount++;
    }

    void deposit(double money) {
        if (money > 0) {
            balance += money;
        }
    }

    void withdraw(double money) {
        if (money > 0 && money <= balance) {
            balance -= money;
        } else {
            cout << owner << " 取款失败，余额不足或金额不合法" << endl;
        }
    }

    void showBalance() {
        cout << owner << " 的余额: " << balance << endl;
    }
};

// 静态成员变量必须在类外初始化
int BankAccount::accountCount = 0;

// 案例 4：类的组合
class Engine {
public:
    void start() {
        cout << "发动机启动" << endl;
    }
};

class Car {
private:
    string brand;
    Engine engine; // Car 类中包含 Engine 对象，这叫“组合”

public:
    Car(string brand) {
        this->brand = brand;
    }

    void drive() {
        cout << brand << " 准备行驶: ";
        engine.start();
    }
};

// 案例 5：继承
class Animal {
protected:
    // protected 表示本类和子类可以访问，外部不能直接访问
    string name;

public:
    Animal(string name) {
        this->name = name;
    }

    void eat() {
        cout << name << " 正在吃东西" << endl;
    }
};

class Dog : public Animal {
public:
    // 子类构造函数调用父类构造函数
    Dog(string name) : Animal(name) {
    }
    vector<int> v;
    void bark() {
        cout << name << " 正在汪汪叫" << endl;
    }
};

// 案例 6：多态
class Shape {
public:
    // virtual 表示虚函数，子类可以重写它
    virtual double area() {
        return 0;
    }

    // 有虚函数的类，通常建议写虚析构函数
    virtual ~Shape() {
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) {
        this->radius = radius;
    }

    // override 表示重写父类的虚函数
    double area() override {
        return 3.14159 * radius * radius;
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double side) {
        this->side = side;
    }

    double area() override {
        return side * side;
    }
};

int main() {
    cout << "===== 案例 1：类、对象、封装 =====" << endl;
    Student stu("张三", 18, 92.5);
    stu.showInfo();
    stu.setScore(96);
    cout << "修改后的成绩: " << stu.getScore() << endl;

    cout << "\n===== 案例 2：this 指针 =====" << endl;
    Rectangle rect(5, 3);
    cout << "矩形面积: " << rect.getArea() << endl;
    cout << "矩形周长: " << rect.getPerimeter() << endl;

    cout << "\n===== 案例 3：静态成员 =====" << endl;
    BankAccount account1("李四", 1000);
    BankAccount account2("王五", 500);
    account1.deposit(200);
    account2.withdraw(800);
    account1.showBalance();
    account2.showBalance();
    cout << "当前账户数量: " << BankAccount::accountCount << endl;

    cout << "\n===== 案例 4：类的组合 =====" << endl;
    Car car("比亚迪");
    car.drive();

    cout << "\n===== 案例 5：继承 =====" << endl;
    Dog dog("小黑");
    dog.eat();  // 调用父类 Animal 的函数
    dog.bark(); // 调用子类 Dog 自己的函数

    cout << "\n===== 案例 6：多态 =====" << endl;
    vector<Shape*> shapes;
    shapes.push_back(new Circle(3));
    shapes.push_back(new Square(4));

    for (Shape* shape : shapes) {
        // 虽然指针类型都是 Shape*，但实际调用的是子类自己的 area()
        cout << "图形面积: " << shape->area() << endl;
    }

    // new 出来的对象要 delete，避免内存泄漏
    for (Shape* shape : shapes) {
        delete shape;
    }
    int a = 4;
    return 0;
}
