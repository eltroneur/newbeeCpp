#include <iostream>
#include <vector>

template <typename T>
bool binarySearch(T val, const std::vector<T> &vec, int &index)
{
  auto beg = vec.begin(), end = vec.end();
  auto mid = beg + (end - beg) / 2;

  while (mid != end && *mid != val)
  {
    if (val < *mid)
      end = mid;
    else
      beg = mid + 1;
    mid = beg + (end - beg) / 2;
  }
  if (*mid == val)
  {
    index = mid - vec.begin();
    return true;
  } else
  {
    return false;
  }
}

template <typename T>
void search(T val, const std::vector<T> &vec)
{
  int index = 0;
  if (binarySearch(val, vec, index))
  {
    std::cout << val << " found, index=" << index << std::endl;
  } else
  {
    std::cout << val << " not found!" << std::endl;
  }
  return;
}

int main()
{
  std::vector<int> iVec;
  for (int i = 1; i < 100; ++i)
  {
    iVec.push_back(i);
  }

  search(66, iVec);
  search(16, iVec);
  search(203, iVec);
  
  return 0;
}
