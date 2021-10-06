#include <iostream>
#include <vector>

int main()
{
# if defined(__sgi)
  std::cout << "__sgi" << std::endl;
#endif

# if defined(__GNUC__)
  std::cout << __GNUC__ << ' ' << __GNUC_MINOR__ << std::endl;
  std::cout << __GLIBC__ << std::endl;
#endif
// case 2
#ifdef __STL_NO_DRAND48
  std::cout << "__STL_NO_DRAND48 defined" << std::endl;
#else
  std::cout << "__STL_NO_DRAND48 undefined" << std::endl;
#endif

// case 3
#ifdef __STL_STATIC_TEMPLATE_MEMBER_BUG
  std::cout << "__STL_STATIC_TEMPLATE_MEMBER_BUG defined" << std::endl;
#else
  std::cout << "__STL_STATIC_TEMPLATE_MEMBER_BUG undefined" << std::endl;
#endif
  // case 5
#ifdef __STL_CLASS_PARTIAL_SPECILIZATION
  std::cout << "__STL_CLASS_PARTIAL_SPECILIZATION defined" << std::endl;
#else
  std::cout << "__STL_CLASS_PARTIAL_SPECILIZATION undefined" << std::endl;
#endif

  return 0;
}
