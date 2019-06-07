#include <stdio.h>

typedef int (*FP_CALC)(int , int);

int add(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int div(int a, int b)
{
    return b ? a/b : -1;
}

FP_CALC calc_func(char op)
{
    switch (op)
    {
        case '+' : return add;
        case '-' : return sub;
        case '*' : return mul;
        case '/' : return div;
        default:
            return NULL;
    }
    return NULL;
}

int (*s_calc_func(char op)) (int, int)
{
    return calc_func(op);
}

int calc(int a, int b, char op)
{
    FP_CALC fp = calc_func(op);
    int (*s_fp)(int, int) = s_calc_func(op);
    // assert(fp == s_fp);
    if (fp)
    {
        return fp(a, b);
    }
    else
        return -1;
}

int main()
{
    int a = 100, b = 20;

    printf("calc(%d, %d, %c) = %d\n", a, b, '+', calc(a, b, '+'));
    printf("calc(%d, %d, %c) = %d\n", a, b, '-', calc(a, b, '-'));
    printf("calc(%d, %d, %c) = %d\n", a, b, '*', calc(a, b, '*'));
    printf("calc(%d, %d, %c) = %d\n", a, b, '/', calc(a, b, '/'));

    return 0;
}