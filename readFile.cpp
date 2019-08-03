// readFile.cpp -- using ifstream
#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{
  char file[20];
  std::cin >> file;
  if (std::cin.eof())
  {
    std::cout << "gets EOF, exiting...\n";
    exit(-1);
  }
  std::ifstream inFile;
  inFile.open(file);

  if (!inFile.is_open())
  {
    std::cout << "Error! File not exists\n";
    exit(-1);
  }

  // using int type to detect type mismatch
  int buf;
  inFile >> buf;
  while(inFile.good())
  {
    std::cout << buf << "-";
    inFile >> buf;
  }

  if (inFile.eof())
  {
    std::cout << "file reach EOF .\n";
    // same as std::cin, if gets a EOF,
    // the following input are invalid
  
  } else if (inFile.fail())
  {
    std::cout << "content type mismatch.\n";

  } else
    std::cout << "Unknown error!" << std::endl;

  inFile.close();

  return 0;
}
