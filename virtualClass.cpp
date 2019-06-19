// virtualClass.cpp -- using virtual class
#include <iostream>

class Animal
{
public:
  Animal() {}
  virtual ~Animal() 
  {
    std::cout << "A animal died." << std::endl;
  };
  virtual void born() const = 0;
  virtual void dead() const = 0;
};

class Human : public Animal
{
public:
  virtual void born() const // keyword virtual could dismiss
  {
    std::cout << "A baby was born! " << std::endl;
  }
  void dead() const // without this method implementation, 
		   // class Human cannot instantiate an object
		   // because it has a pure virtual method 'dead'
  {
    std::cout << "This person died. " << std::endl;
  }
  virtual ~Human() // keyword virtual could dismiss
  {
    std::cout << "A human dead(virtual).." << std::endl;
  }
};

class feline : public Animal  // still an abstract class 
                              // because lack of implementation
{
public:
  void dead() const
  {
    std::cout << "A feline died. " << std::endl;
  }

  virtual ~feline()
  {
    std::cout << "A feline died( virtual )" << std::endl;
  }
};

class cat : public feline
{
public:
  void born() const
  {
    std::cout << "A little kitty was borned. " << std::endl;
  }

  void stick_person(int count)
  {
    for (int i = 0; i < count; ++i)
    {
      std::cout << "Miao~" << " ";
    }
    std::cout << std::endl;
  }
  virtual ~cat()
  {
    std::cout << "A cat died(virtual)" << std::endl;
  }
};


int main()
{
  Human nobody;
  nobody.born();

  std::cout << "After 5 years..." << std::endl;

  //nobody.dead();

  //feline f1; // cannot instantiate an abstract class object
  cat orangeCat;
  orangeCat.born();
  orangeCat.stick_person(3);
  //std::cout << "An accendent occured... >_<" << std::endl;
  //orangeCat.dead();

  Animal *a1 = new Human();

  delete a1;  // memory leak if not do this

  Human *h1 = new Human();
  delete h1;

  return 0;
}
