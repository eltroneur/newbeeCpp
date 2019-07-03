// binarySearch.cpp -- binary search
#include <iostream>
#include <algorithm>
#include <iterator>

int rank(int arr[], int length, int val)
{
  int lo = 0;
  int hi = length - 1;
  while (lo <= hi)
  {
    int mid = lo + (hi - lo)/2;
    std::cout << "lo = " << lo << ", mid = " << mid << ", hi = " << hi << ", arr[mid] = " << arr[mid] << std::endl;
    
    if (arr[mid] > val) 
      hi = mid - 1;
    else if (arr[mid] < val) 
      lo = mid + 1;
    else 
      return mid;
  }
  return -1;
}

int main()
{
  int arr[8] = {4, 88, 16, 21, 15, 54, 67, 13};
  std::sort(arr+0, arr+8);
  //std::copy(arr, arr+8, std::ostream_iterator<char>(std::cout, " "));
  for (int i = 0; i < 8; ++i)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  int result = rank(arr, 8, 19);
  if (result == -1)
  {
    std::cout << "Not found.";
  }
  else
  {
    std::cout << "pos is " << result << std::endl;
  }

}
