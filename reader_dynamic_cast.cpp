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
    readRep();
  }

  void compress() const
  {
    std::cout << "compressing... "  << std::endl;
  }

private:
  void readRep() const
  {
    std::cout << "Repetition..." << std::endl;
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
  // No need this operation
  //rb = dynamic_cast<GDSReader *>(&gds);
  // Just static_cast
  rb = static_cast<ReaderBase *>(&gds);
  rb->read();

  OASReader oas;
  //rb = dynamic_cast<OASReader *>(&oas);
  rb = &oas;

  rb->read();  // fine
  //rb->compress();  // Error: class has no member named compress
  OASReader *poas = dynamic_cast<OASReader *>(rb);
  poas->compress();

  ReaderBase *mp_delegate;
  mp_delegate = &oas;
  mp_delegate->read();
  

  return 0;
}
