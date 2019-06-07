#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>

std::mutex mu;
class LogFile
{
    std::mutex m_mutex;
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
        std::lock_guard<std::mutex> guard(m_mutex);
        f << msg << id << std::endl;
    }
};

void function_1(LogFile &log)
{
    for (int i = 0; i > -10; --i)
    {
        log.shared_print(std::string("From t1: "), i);
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