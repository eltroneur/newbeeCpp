#include <functional> // needed by std::less
#include <iostream>

template<class A, class B, class U = std::less<>>
bool f(A a, B b, U u = U())
{
  return u(a, b);
}

template <class T, class Comp=std::less<> >
bool cmp(T a, T b, Comp comp={})
{
  return comp(a, b);
}

int main()
{
  std::cout << std::boolalpha; // enable std::cout display bool[true|false]\
				// instead [1 | 0]
  std::cout << f(5, 20) << '\n';
  std::cout << f(88, 66) << '\n';

  std::less<char> char_cmp;
  std::cout << char_cmp('M', 'X') << std::endl;

  std::cout << cmp("hello", "hello1") << std::endl;

  return 0;
}
