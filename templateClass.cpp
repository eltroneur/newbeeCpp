// templateClass.cpp -- class using template
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

template <class T>
class Stack
{
private:
  std::vector<T> elems;

public:
  void push(T const&);
  void pop() const;
  T top() const;
  void display() const;
  bool empty() const
  {
    return elems.empty();
  }
};

template <class T>
void Stack<T>::push(T const &elem)
{
  elems.push_back(elem);
}

template <class T>
void Stack<T>::pop() const
{
  if (elems.empty())
  {
    throw std::out_of_range("Stack<>::pop(): empty stack");
  }
    elems.pop_back();  // Error if a const method specified
    //elems.empty();  // Fine, a const or non-const method could use
}

template <class T>
T Stack<T>::top() const
{
  if (elems.empty())
  {
    throw std::out_of_range("Stack<>::pop(): empty stack");
  }
  return elems.back();
}

template <class T>
void Stack<T>::display() const
{
  typename std::vector<T>::const_iterator iter = elems.begin();
  while (iter != elems.end() )
  {
    std::cout << *iter << std::endl;
    ++iter;
  }
}

int main()
{
  try
  {
  Stack<int> stack_int;
  stack_int.push(88);
  stack_int.push(96);

  stack_int.display();

  Stack<std::string> stack_str;
  stack_str.push("Shinelon");
  stack_str.push("Hassee");
  stack_str.push("Alienware");

  stack_str.display();

  stack_int.pop();

  stack_str.pop();
  stack_str.pop();
  stack_str.pop();
  stack_str.pop();

  stack_int.display();
  }
  catch (std::exception const& ex)
  {
    std::cerr << "Exception: " << ex.what() << std::endl;
    return -1;
  }

  return 0;
}
