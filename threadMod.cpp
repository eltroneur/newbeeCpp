#include <iostream>
#include <thread>
#include <string>

class Factor
{
public:
    //typedef int type;
    // one param -- reference
    void operator() (std::string& msg)
    {
        msg = "world";
    }
    void operator() (int i)
    {
        typedef bool type;
        std::cout << "param is " << i << std::endl;
    }
};

int main()
{
    Factor f;
    std::string m = "hello";
    //std::thread t1(f, std::ref(m)); // correct
    std::thread t1(f, 3);  // wrong

    t1.join();
    std::cout << m << std::endl;

    return 0;
}
