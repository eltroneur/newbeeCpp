// cstr.cpp -- using c_str()
#include <iostream>
#include <cstring>

void showCString(const char *cstr)
{
  std::cout << cstr << std::endl;
}

int main()
{
  std::string str("Hello CString");
  showCString(str.c_str());

  return 0;
}

