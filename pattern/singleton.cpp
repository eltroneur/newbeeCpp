#include <iostream>

class Single
{
public:
  static Single *getInstance()
  {
    if (!ptr)
      ptr = new Single('A');
    return ptr;
  }
  void display() const
  {
    std::cout << "Captial is " << m_char << std::endl;
  }
private:
  Single(char C) : m_char(C) {}
  static Single *ptr;
  char m_char;
};

static Single *ptr = nullptr;

int main()
{
  Single::getInstance()->display();

  return 0;
}
