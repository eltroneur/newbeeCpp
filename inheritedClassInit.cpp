// inheritedClassInit.cpp -- A inherited class initialize test
#include <iostream>

class Human
{
public:
  explicit Human(int desire = 0) : m_desire(desire)
  {
    
  }
  void show()
  {
    std::cout << "Basically, this human's desire value is: " << m_desire << std::endl;
  }
private:
  int m_desire;
};

class CollageGirl : public Human
{
public:
  CollageGirl(int desire, int money) : Human(desire), m_money(money)
  {
    
  }

  void express()
  {
    show();
    std::cout << "And as a CollageGirl, her money desired value is " << m_money << std::endl;
  }
private:
  int m_money;
};

int main()
{
  CollageGirl slut1(50, 20);

  slut1.express();
}
