#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void)
{
  int c = EOF;
  while ( (c = getc(stdin) ) != EOF)
  {
    if ( c != putc(c, stdout) )
    {
      printf("Writing error!\n");
      exit(-1);
    }
    printf("====\n");
  }
  printf("End...\n");

  return 0;
}
