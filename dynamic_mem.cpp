// dynamic_mem.cpp -- using malloc & new
#include <iostream>
#include <malloc.h>

class Person
{
public:
  Person() : m_weight(-1)
  {
    std::cout << "A facade baby created!" << std::endl;
  }
  Person(int kg) : m_weight(kg)
  {
    std::cout << "A new baby weights " << m_weight << " KG." << std::endl;
  }
  ~Person()
  {
    delete &m_weight;
    std::cout << "Baby dying -_-" << std::endl;
  }
  void setWeight(int kg)// : m_weight(kg) // only constructors take member initializers
  {
    m_weight = kg;
  }
  void Print()
  {
    std::cout << "my weight is " << m_weight << std::endl;
  }

private:
  int m_weight;
};

int main()
{
  Person *doubleBaby_new = new Person[2];

  //doubleBaby_new = new Person(8);
  //doubleBaby_new = new Person(5);
  doubleBaby_new[0].Print();
  doubleBaby_new[1].Print();

  doubleBaby_new[0].setWeight(8);
  doubleBaby_new[1].setWeight(5);

  doubleBaby_new[0].Print();
  doubleBaby_new[1].Print();

  Person *doubleBaby_mal = (Person *)malloc(2 * sizeof(Person));
  
  doubleBaby_mal[0].Print();
  doubleBaby_mal[1].Print();

  delete []doubleBaby_new;
  free(doubleBaby_mal);

  doubleBaby_new[0].Print();
  doubleBaby_new[1].Print();

  return 0;
}
