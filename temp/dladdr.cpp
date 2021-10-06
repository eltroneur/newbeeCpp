#include <stdio.h>
#include <dlfcn.h>
#include <sys/types.h>


int main()
{

  Dl_info soInfo;
  int iRet = 0;
  iRet = dladdr((void *)dlopen, &soInfo);
  if(iRet == 0)
  {
    printf("dladdr failed!\n");
    return -1;
  }

  printf("dli_fname=%s\n", soInfo.dli_fname);
  printf("dli_fbase=0x%x\n", soInfo.dli_fbase);
  printf("dli_sname=%s\n", soInfo.dli_sname);
  printf("dli_saddr=0x%x\n", soInfo.dli_saddr);

  return 0;
}
