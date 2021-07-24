// myls.cpp
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("usage: %s dirname\n", argv[0]);
    exit(-1);
  }

  DIR *objDir = NULL;
  objDir = opendir(argv[1]);
  if (NULL == objDir)
  {
    int iErr = errno;
    perror("Err when opening directory");
    exit(-1);
  }

  struct dirent *subItem = NULL;
  while ( (subItem = readdir(objDir)) )
  {
    printf("%s ", subItem->d_name);
  }

  printf("\n");

  closedir(objDir);

  return 0;
}
