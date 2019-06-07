#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>

class LogFile
{
    std::mutex _mu;
    std::mutex _mu2;
    std::ofstream f;
public:
    LogFile()
    {
        f.open("log.txt");
    }
    ~LogFile()
    {
        f.close();
    }

    void shared_print(std::string msg, int id)
    {
        std::lock_guard<std::mutex> guard(_mu);
        std::lock_guard<std::mutex> guard2(_mu2);
        f << msg << id << std::endl;
        std::cout << msg << id << std::endl;
    }

    void shared_print2(std::string msg, int id)
    {
        std::lock_guard<std::mutex> guard(_mu2);
        std::lock_guard<std::mutex> guard2(_mu);
        f << msg << id << std::endl;
        std::cout << msg << id << std::endl;
    }
};

void function_1(LogFile &log)
{
    for (int i = 0; i > -10; --i)
    {
        log.shared_print2(std::string("From t1: "), i);
    }
}

int main()
{
    LogFile log;
    std::thread t1(function_1, std::ref(log));

    for (int i = 0; i < 10; ++i)
    {
        log.shared_print(std::string("From main: "), i);
    }

    t1.join();

    return 0;
}