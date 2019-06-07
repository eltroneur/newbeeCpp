// twoDarray.cpp -- A 2-D Array
#include <iostream>

int main()
{
  int **array;
  int const row = 8;
  int const col = 4;

  array = new int* [row];

  for (int i = 0; i < row; ++i)
  {
    array[i] = new int[col];
  }

  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < col; ++j)
    {
      array[i][j] = i*j;
    }
  }

  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < col; ++j)
    {
      std::cout << "array[" << i << "][" << j << "] = " << array[i][j] << " ";
    }
    std::cout << std::endl;
  }

  for (int i = 0; i < row; ++i)
  {
    delete []array[i];
  }

  delete []array;

  return 0;
}
