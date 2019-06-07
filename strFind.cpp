// strFind.cpp -- using find() method of string
#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char *argv[])
{
  std::string gds = "/nfs/devel/gds/b.gds";
  std::string oas = "/nfs/deve/oas/thinker.oas";
  std::string fileName = argv[1];
  
  size_t pos = fileName.find('.');
  std::string format(fileName, pos, 4);

  //std::cout << format << std::endl;
  if (format == ".gds")
  {
    std::cout << "GDSReader invoked! " << std::endl;
  }
  else if (format == ".oas")
  {
    std::cout << "OASReader invoked! " << std::endl;
  }
  else
  {
    std::cerr << "Wrong file type! " << std::endl;
    exit(-1);
  }

  return 0;
}
