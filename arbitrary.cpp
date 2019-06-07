#include <iostream>

typedef int arr[3];
typedef void (*pfun)(void);



int main()
{
    arr A1;
    A1[0] = 10;
    A1[1] = 66;
    A1[2] = 88;

    pfun main;

    return 0;
}
