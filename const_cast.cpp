// const_cast.cpp -- using const cast
#include <iostream>

void InputInt(int *num)
{
  std::cout << *num << std::endl;
}

int main()
{
  //const int source = 88;
  const volatile int source = 88;
  const volatile int *pc = &source;
  //*pc = 99; // Error: Assignment of read-only location
  int *pnc = const_cast<int *>(pc);
  //volatile int *pnc = const_cast<volatile int *>(pc); // volatile is not necessary
  std::cout << "&source = " << &source << ", pc = " << pc << ", pnc = " << pnc << std::endl;
  std::cout << "source = " << source << ", *pc = " << *pc << ", *pnc = " << *pnc << std::endl;
  std::cout << "Assign *pnc to a new val: 99\n";
  *pnc = 99;
  std::cout << "&source = " << &source << ", pc = " << pc << ", pnc = " << pnc << std::endl;
  std::cout << "source = " << source << ", *pc = " << *pc << ", *pnc = " << *pnc << std::endl;
  // Result is : the value of source doesn't change, but *pc and *pnc has been chagnged. Addresses of three variable don't change either.
  // The fact is variable source was declared using const keyword, program will read the value through cache because it doesn't know this value may be changed. // If using volatile in declaration of three variables, source will show as changed value
  
  const int origin = 66;
  // without converting
  //InputInt(&origin); // Error: Invalid conversion from "const int*" to "int*"
  int *param = const_cast<int *>(&origin);
  InputInt(param);

  // use a pointer (which are point to const int ) to modify a non-const int value
  int value = 10;
  const int *pcv = &value;
  //*pcv = 78;  // Error: Assignment of read-only location
  int *modifier = const_cast<int *>(pcv);
  *modifier = 16;
  std::cout << "value = " << value << std::endl;

  return 0;
}
