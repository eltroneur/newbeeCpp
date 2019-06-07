// functionNthread.cpp 
#include <iostream>
#include <functional>
#include <thread>

class A
{
public:
    void func1()
    {

    }

    void func2(int i)
    {

    }
    void func3(int i, int j)
    {

    }

};

int main()
{
    A a;
    std::function<void(void)> f1 = std::bind(&A::func1, &a);
    std::function<void(void)> f2 = std::bind(&A::func2, &a, 1);
    std::function<void(int)> f3 = std::bind(&A::func2, &a, std::placeholders::_1);
    std::function<void(int)> f4 = std::bind(&A::func3, &a, 1, std::placeholders::_1);
    std::function<void(int, int)> f5 = std::bind(&A::func3, &a, std::placeholders::_1, std::placeholders::_2);

    std::thread t1(f1);
    std::thread t2(f2);
    std::thread t3(f3, 1);
    std::thread t4(f4, 1);
    std::thread t5(f5, 1, 2);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}