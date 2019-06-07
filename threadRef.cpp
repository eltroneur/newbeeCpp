#include <iostream>
#include <thread>
#include <string>
#include <unistd.h>

class A
{
public:
    A()
    {
        std::cout << "default constructor.." << std::endl;
    }
    A(const A &ref)
    {
        std::cout << "copy constructor.." << std::endl;
    }
    void f(int x, char c) 
    {
        std::cout << "f:two params: " << x << " , "  << c << std::endl;
    }
    int g(double x) { 
        std::cout << "g:one params: " << x << std::endl;
        return 0; 
    }
    int operator() (int N) { 
        std::cout << "(): one param: " << N << std::endl;
        return 0; 
    }
};

void foo(int x) {}

int main()
{
    A a;
    std::thread t1(a, 6);
    t1.join();
    getchar();
    /*std::thread t2(std::ref(a), 8);
    t2.join();
    getchar();
    std::thread t3(A(), 10);
    t3.join();
    getchar();
    std::thread t4(&A::f, a, 8, 'w');
    t4.join();
    getchar();
    std::thread t5(&A::f, &a, 8, 'w');
    t5.join();
    getchar();
    std::thread t6(std::move(a), 6);
    t6.join();
    getchar();*/

    return 0;
}