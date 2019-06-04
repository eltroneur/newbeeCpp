// moreException.cpp -- more exception
#include <iostream>
#include <exception>

class MyException
{
public:
  MyException(const char *message) : message_(message)
  {
    std::cout << "MyException ..." << std::endl;
  }
  MyException(const MyException &other) : message_(other.message_)
  {
    std::cout << "Copy MyException ..." << std::endl;
  }
  virtual ~MyException()
  {
    std::cout << "~MyException ..." << std::endl;
  }

  const char *what() const
  {
    return message_.c_str();
  }

private:
  std::string message_;
};

class MyExceptionD : public MyException
{
public:
  MyExceptionD(const char *message) : MyException(message)
  {
    std::cout << "MyExceptionD ..." << std::endl;
  }
  MyExceptionD(const MyExceptionD &other) : MyException(other)
  {
    std::cout << "Copy MyExceptionD ..." << std::endl;
  }
  ~MyExceptionD()
  {
    std::cout << "~MyExceptionD ..." << std::endl;
  }
};

void fun(int n) throw (int, MyException, MyExceptionD)
{
  if (n == 1)
  {
    throw 1;
  }
  else if (n == 2)
  {
    throw MyException("test Exception");
  }
  else if (n == 3)
  {
    throw MyExceptionD("test ExceptionD");
  }
}

void fun2() throw()
{

}

int main()
{
  try
  {
    fun(2);
  }
  catch (int n)
  {
    std::cout << "catch int ..." << std::endl;
    std::cout << "n = " << n << std::endl;
  }
  catch (MyException &me)
  {
    std::cout << "catch MyException ... " << std::endl;
    std::cout << me.what() << std::endl;
  }

  MyExceptionD med("I am origin");
  MyExceptionD med_clone(med);
  std::cout << med_clone.what() << std::endl;

  return 0;
}
