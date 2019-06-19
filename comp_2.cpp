// comp_2.cpp
#include <iostream>
#include <functional>

template<class T, class Comp = std::less<> >
bool myComp(T const &a, T const &b, Comp cmp = {})
{
  return cmp(a, b);
}

template<class T>
struct s_cmp
{
  bool operator() (T a, T b)
  {
    return std::less<>() (a, b);
    //return a < b;
  }
};

int main()
{
  std::cout << myComp(3, 18) << std::endl;
  //s_cmp<int> structCmp;
  std::cout << s_cmp<int>() (2, 1) << std::endl;
  s_cmp<int> inst;
  inst(3, 5);

  return 0;
}
