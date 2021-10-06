#include <iostream>

template <class I, class O>
struct testClass
{
  testClass() { std::cout << "I, O" << std::endl; }
};

// special
template <class T>
struct testClass<T *, T *>
{
  testClass() { std::cout << "T*, T*" << std::endl; }
};

template <class T>
struct testClass<const T*, T*>
{
  testClass() { std::cout << "const T*, T*" << std::endl; }
};

// another test
class alloc 
{};

template <class T, class Alloc = alloc>
class vector
{
public:
  void swap(vector<T, Alloc> &) { std::cout << "swap()" << std::endl; }
};

//#ifdef __STL_FUNCTION_TMPL_PARTIAL_ORDER
template <class T, class Alloc>
inline void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
{
  x.swap(y);
}
//#endif

int main()
{
  testClass<int, char> obj1;  // I, O
  testClass<int *, int *> obj2; // T*, T*
  testClass<const int *, int *> obj3; // const T*, T*

  vector<int> x, y;
  swap(x, y);
#ifdef __STL_FUNCTION_TMPL_PARTIAL_ORDER
  std::cout << "__STL_FUNCTION_TMPL_PARTIAL_ORDER defined" << std::endl;
#else
  std::cout << "__STL_FUNCTION_TMPL_PARTIAL_ORDER undefined" << std::endl;
#endif

  return 0;
}

