// cstr.cpp -- using c_str()
#include <iostream>
#include <cstring>

int main()
{
  std::string str("Origin strings content is here");
  std::cout << "strcpy((char *)str.c_str(), XXXXXXXX)" << std::endl;
  strcpy((char *)str.c_str(), "XXXXXXXX");
  std::cout << "str = " << str << " ===> " << str.c_str() << std::endl;
  str.append("Append");
  std::cout << str << " ===> " << str.c_str() << std::endl;
  std::string str2("Correct one.");
  str2.append("cAppend.");
  std::cout << "str2 = " << str2 << " ===> " << str2.c_str() << std::endl;

  const char *cstr = "Hello str";
  //*cstr = "Android";
  strcpy((char *)cstr, "Android");

  return 0;
}
