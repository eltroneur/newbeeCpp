// noInstantiateFuncCall.cpp
#include <iostream>

template <class CurrencyType>
struct shop
{
  static void onSale(CurrencyType type)
  {
    std::cout << "This shop on sale, and only use " << type << std::endl;
    //std::cout << "Amount is " << amount << std::endl; // cannot use non-static members in static method
  }
  void showAmount()
  {
    std::cout << "Amount is " << amount << std::endl;
  }
  int amount = 100;  // non-static data member initializer only available with 
                     // -std=c++11 or -std=gnu++11
};

int main()
{
  shop<char>().onSale('C');
  shop<char>().showAmount();

  return 0;
}
