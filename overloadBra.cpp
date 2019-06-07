// overloadBra.cpp -- overload the operator bra
#include <iostream>
#include <thread>

class Bra
{
public:
    void operator() ()
    {
        std::cout << "No size no bra" << std::endl;
    }
    void operator() (char size)
    {
        std::cout << "Wow " << size << " breast!" << std::endl;
    }
};

void function_1()
{
    std::cout << "No parameter passed!" << std::endl;
}

void function_1(int i)
{
    std::cout << "One parameter passed!" << std::endl;
}

void function_1(int i, std::string m)
{
    std::cout << "Two parameter passed!" << std::endl;
}

class Factor
{
public:
    Factor ()
    {
        std::cout << "Normal constructor..." << std::endl;
    }
    Factor (int i)
    {
        std::cout << "Single " << i << " constructor..." << std::endl;
    }
    void operator() ()
    {
        std::cout << "operator bra called!" << std::endl;
    }
};

int main()
{
    Bra bra1;
    bra1('S');
    //std::thread t1(function_1);
    //std::thread t2(function_1, 1);
    //std::thread t3(function_1, 1, "hello");

    //t1.join();
    //t2.join();
    //t3.join();
    Factor f;
    Factor f4(10);
    std::thread t1(f);
    t1.join();
    //std::thread t2();

    std::thread t_a([]() {
        std::cout << "Anonymous function" << std::endl;
    });
    std::thread t_a1([] (std::string m) {
        std::cout << "Anonymous function with parameter " << m  << std::endl;
    });

    t_a.join();
    t_a1.join();

    

    return 0;
}