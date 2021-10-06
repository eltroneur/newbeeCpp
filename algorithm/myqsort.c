#include <stdio.h>

void swap(int *arr, int a, int b)
{
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

void qsort(int *arr, int len)
{
  int base = arr[0];
  int low = 0, high = len - 1;
  while (low < high)
  {
    while (arr[high] >= arr[low] && low < high)
    {
      --high;
    }
    arr[low] = arr[high];
    for (int i = low + 1; low < high; ++i)
    {
      if (arr[i] > base)
      {
        arr[high] = arr[i];
        arr[i] = base;
        low = i;
        break;
      }
    }
    
  }

}

int main(int argc, char *argv[])
{
  int arr[] = {49, 38, 65, 97, 76, 13, 27, 49};
  qsort(arr, sizeof arr / sizeof(int));
  for (int i = 0; i < (sizeof arr)/4; ++i)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
