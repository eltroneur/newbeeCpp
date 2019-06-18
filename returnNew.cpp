// returnNew.cpp -- return a new class object
#include <iostream>

class FormatSpecificReaderOptions
{
public:
  FormatSpecificReaderOptions () {}
  virtual ~FormatSpecificReaderOptions () {} // to enable RTTI

  virtual FormatSpecificReaderOptions *clone() const = 0;
  virtual const std::string &format_name() const = 0;
};

class OASISReaderOptions 
  : public FormatSpecificReaderOptions
{
public:
  OASISReaderOptions ()
  : read_all_properties(false), expect_strict_mode(-1)
  {
    
  }

  bool read_all_properties;

  int expect_strict_mode;

  std::string *str;

  virtual FormatSpecificReaderOptions *clone() const
  {
    return new OASISReaderOptions(*this);
  }

  virtual const std::string &format_name() const
  {
    static const std::string n("OASIS");
    return n;
  }
};

int main()
{
  OASISReaderOptions *oas = new OASISReaderOptions();
  
  oas->str = new std::string("Located in heap.");

  FormatSpecificReaderOptions *copy = oas->clone();

  std::cout << oas->format_name() << std::endl;

  delete oas;

  OASISReaderOptions* a = dynamic_cast<OASISReaderOptions *>(copy);

  std::cout << copy->format_name() << std::endl; // still there
  std::cout << copy->str << std::endl;

  return 0;
}
