// reload_const_member_function.cpp 
// using const qulifier to reload a member function
#include <iostream>

class A
{
public:
  void print()
  {
    std::cout << "Non-const print() called!" << std::endl;
  }

  // reloading print() by const
  void print() const
  {
    std::cout << "Const print() called!" << std::endl;
  }
};

#if 0
class B
{
public:
  // this class cannot be overloaded
  // because the exist of const qulifier 
  // doesn't affect anything, the following
  // 2 function is equivalent
  void print(const int a)
  {
    
  }
  void print(int a)
  {
    
  }
};
#endif

class C
{
public:
  // this function can be overloaded
  // because in function, char *a can
  // modify the original value
  void print(char *a)
  {
  
  }
  // but this a cannot mofify
  // the original value, so they are different
  void print(const char *a)
  {
  
  }
};

#if 0
class D
{
public:
  // same as class B
  void print(char *a)
  {
 
  }
  void print(char *const a)
  {
 
  }
};
#endif

class E
{
public:
  void print(const int& a)
  {
  
  }

  void print(int &a)
  {
  
  }
};

int main()
{
  // a non-const object will call 
  // non-const reloading method firstly
  A n_a;
  n_a.print();

  // a const object will call
  // const reloading method firstly
  const A c_a;
  c_a.print();
}
