#include <iostream>

// for a empty class, the size is 1
class Blank
{};

// an empty subclass of an empty class, the size is still 1
class subBlank : public Blank
{};

// a non-empty subclass of an empty clas, the size of base-class (which is 1)
// are optimized out
class subBlankInt : public Blank
{
  int m_i;
};

class vObj
{
public:
  virtual ~vObj();
};

class vSubObj : public vObj
{
public:
  virtual void VRGame();
};

int main(int argc, char *argv[])
{
  // result is 1
  std::cout << "sizeof(Blank)=" << sizeof(Blank) << std::endl;
  // result is 1
  std::cout << "sizeof(subBlank)=" << sizeof(subBlank) << std::endl;
  // result is 4
  std::cout << "sizeof(subBlankInt)=" << sizeof(subBlankInt) << std::endl;

  std::cout << "sizeof(vObj)=" << sizeof(vObj) << std::endl;
  std::cout << "sizeof(vSubObj)=" << sizeof(vSubObj) << std::endl;
  std::cout << "sizeof(void *)=" << sizeof(void *) << std::endl;
  return 0;
}
