// templateClass2.cpp -- my template Class
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <vector>

template <class T>
class BulletStorage
{
public:
  void push(T const& bullet);
  void pop();
  bool empty() const
  {
    return storage.empty();
  }
  T const& top() const;

private:
  std::vector<T> storage;
};

template <class T>
void BulletStorage<T>::push(T const& bullet)
{
  storage.push_back(bullet);
}

template <class T>
void BulletStorage<T>::pop()
{
  if (storage.empty())
  {
    throw std::out_of_range("BulletStorage::pop(): Empty!");
  }
  storage.pop_back();
}

template <class T>
T const& BulletStorage<T>::top() const
{
  if (storage.empty())
  {
    throw std::out_of_range("BulletStorage::top() : Empty!");
  }
  return storage.back();
}

int main()
{
  BulletStorage<int> bs_int;
  try
  {
    //bs_int.pop();
    bs_int.push(18);
    bs_int.push(66);
    std::cout << "Top is : " << bs_int.top() << std::endl;
    bs_int.pop();
    bs_int.pop();
    std::cout << "Top is: " << bs_int.top() << std::endl;
    std::cout << "End..." << std::endl;
  }
  catch(std::exception const& ex)
  {
    std::cerr << ex.what() << std::endl;
    exit(-1);
  }

  return 0;
}
