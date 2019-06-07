#include <iostream>
#include <thread>
#include <string>
#include <mutex>

std::mutex mu;
// using lock
void shared_print(std::string msg, int id)
{
    //std::lock_guard<std::mutex> guard(mu);
    mu.lock();
    std::cout << msg << id << std::endl;
    mu.unlock();
}

void function_1()
{
    for (int i = 0; i > -10; --i)
    {
        shared_print(std::string("From t1: "), i);
    }
}

int main()
{
    std::thread t1(function_1);

    for (int i = 0; i < 10; ++i)
    {
        shared_print(std::string("From main: "), i);
    }

    t1.join();

    return 0;
}