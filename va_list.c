#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int IntAvg(int count, ...);
char *BlendStr(int n, ...);
void error(const char *fmt, ...);

int main()
{
  
  printf("IntAvg(3, 4, 5, 6) = %d\n", IntAvg(3, 4, 5, 6));
  BlendStr(2, "Dead", " Space Fallapart");
  error("they're comming, shutting down...");

  return 0;
}

int IntAvg(int count, ...)
{
  va_list vlist;
  va_start(vlist, count);

  int temp;
  int sum;
  int index;

  index = count;
  temp = -1;
  sum = 0;
  while (index -- > 0)
  {
    temp = va_arg(vlist, int);
    printf("temp = %d\n", temp);
    sum += temp;
  }

  return sum / count;

}

char *BlendStr(int count, ...)
{
  va_list strList;

  int index = 0;
  index = count;
  va_start(strList, count);

  while ( index -- > 0)
  {
    printf("%s", va_arg(strList, const char *));
  }
  printf("\n");
  va_end(strList);

  return NULL;
}

void error(const char *fmt, ...)
{
  va_list argList;

  va_start(argList, fmt);
  fprintf(stderr, "error:");
  vfprintf(stderr, fmt, argList);
  fprintf(stderr, "\n");
  va_end(argList);

  exit(-1);
}
