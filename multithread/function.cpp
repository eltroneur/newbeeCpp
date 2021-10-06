#include <functional>
#include <iostream>

struct Foo {
  Foo(int num) : num_(num) {}
  void print_add(int i) const { std::cout << num_+i << '\n'; }
  int num_;
};

void print_num(int i)
{
  std::cout << i << '\n';
}

struct PrintNum {
  void operator() (int i) const
  {
    std::cout << i << '\n';
  }
};

int main()
{
  // store global function
  std::function<void (int)> f_display = print_num;
  f_display(-9);

  // store lambda
  std::function<void ()> f_display_lambda = [] () { print_num(42); }; 
  f_display_lambda();

  // store std::bind
  std::function<void ()> f_display_bind = std::bind(print_num, 31337);
  f_display_bind();

  // store class member function
  std::function<void (const Foo&, int)> f_add_display = &Foo::print_add;
  const Foo foo(314159);
  f_add_display(foo, 1);
  f_add_display(314159, 1);

  // 存储到数据成员访问器的调用
  std::function<int (const Foo &)> f_num = &Foo::num_;
  std::cout << "num_: " << f_num(foo) << '\n';

  using std::placeholders::_1;
  std::function<void (int)> f_add_display2 = std::bind(&Foo::print_add, foo, _1);
  f_add_display2(2);

  std::function<void (int)> f_add_display3 = std::bind(&Foo::print_add, &foo, _1);
  f_add_display3(3);

  // store function object
  std::function<void (int)> f_display_obj = PrintNum();
  f_display_obj(18);

  return 0;
}
