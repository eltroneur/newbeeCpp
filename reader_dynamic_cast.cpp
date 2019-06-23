// reader_dynamic_cast.cpp
#include <iostream>

class ReaderBase
{
public:
  virtual void read() const = 0;

};

class OASReader : public ReaderBase
{
public:
  virtual void read() const
  {
    std::cout << "Loading OAS file..." << std::endl;
  }

  void compress() const
  {
    std::cout << "compressing... "  << std::endl;
  }
};

class GDSReader : public ReaderBase
{
public:
  virtual void read() const
  {
    std::cout << "Loading GDS file..." << std::endl;
  }
};

int main()
{
  ReaderBase *rb;
  GDSReader gds;
  rb = dynamic_cast<GDSReader *>(&gds);
  rb->read();

  OASReader oas;
  //rb = dynamic_cast<OASReader *>(&oas);
  rb = &oas;

  rb->read();  // fine
  //rb->compress();  // Error: class has no member named compress
  OASReader *poas = dynamic_cast<OASReader *>(rb);
  poas->compress();

  return 0;
}
