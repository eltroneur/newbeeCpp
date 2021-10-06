#include <stdio.h>

void swap(int arr[], int indexA, int indexB)
{
  int swapTemp;
  swapTemp = arr[indexA];
  arr[indexA] = arr[indexB];
  arr[indexB] = swapTemp;
}

void subSort(int arr[], int len)
{
  int low = 0, high = len - 1;
  int temp = arr[low];

  while (low < high)
  {
    while (arr[high] > temp && low < high)
    {
      --high;
    }
    swap(arr, low, high);
    //--low;

    while (arr[low] < temp && low < high)
    {
      ++low;
    }
    swap(arr, low, high);
    //++high;
  }
}

int main(int argc, char *argv[])
{
  int arr[] = {49, 38, 65, 97, 76, 13, 27, 49};
  subSort(arr, (sizeof arr) / sizeof(int));
  for (int i = 0; i < (sizeof arr)/4; ++i)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  return 0;
}
