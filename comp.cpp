// comp.cpp -- using std::compare
#include <iostream>

template < class T, class Comp=std::less<> >
//bool myCmp(T const &a, T const &b, Comp cmp = {} )
//bool myCmp(T const &a, T const &b, Comp cmp = Comp{} )
bool myCmp(T const &a, T const &b, Comp cmp = Comp() )
{
  return cmp(a, b);
}

int main()
{
  int a{};

  std::cout << myCmp(4, 67) << std::endl;
  
  return 0;
}
