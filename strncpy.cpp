#include <cstring>
#include <iostream>

int main()
{
  const char *source = "SOURCE";
  char *dst = new char [strlen(source) + 1];
  strcpy(dst, source);
  std::cout << "dst = " << dst << std::endl;

  char *minor = new char[strlen(source)];
  strncpy(minor, source, 2);
  std::cout << "minor = " << minor << std::endl;
  minor[6] = 'M';
  std::cout << "minor = " << minor << std::endl;

  char src[40];
  char dest[12];

  memset(dest, '\0', sizeof(dest));
  std::cout << "sizeof dest is " << sizeof dest << std::endl;
  strcpy(src, "This is runoob.com");
  strncpy(dest, src, 10);

  std::cout << "Final dest = " << dest << std::endl;

  return 0;
}
