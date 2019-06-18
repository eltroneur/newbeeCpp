// enum.cpp -- using type enum
#include <iostream>

enum cpu { i3, i5, i7, i9, ryzen2500, ryzen2700 };
enum gpu { gtx1050, gtx1060, gtx1070, rx470, rx480};

class pc
{
public:
  pc (cpu c, gpu g) : m_cpu(c), m_gpu(g)
  {
  }
  void show_prop()
  {
    std::cout << "CPU:  " << m_cpu << " GPU: " << m_gpu << std::endl;
  }
  /*void fake_cpu()
  {
    ++m_cpu;  // not valid
  }
  void fake_gpu()
  {
    ++m_gpu;
  }*/

private:
  cpu m_cpu;
  gpu m_gpu;
};

int main()
{
  pc antac(i5, rx480);
  antac.show_prop();
  //antac.fake_cpu;
  //antac.show_prop();

  pc nzxt(i7, gtx1060);
  nzxt.show_prop();

  pc mine(ryzen2700, rx470);
  mine.show_prop();

  std::cout << "i5+1 = " << i5 + 1 << std::endl;
  int result = 2;
  result += ryzen2500;
  std::cout << "result = " << result << std::endl;

  gpu newGpu = rx470;
  //gpu fakeGpu = 3;  // invalid conversion from int to gpu
  

  return 0;
}
