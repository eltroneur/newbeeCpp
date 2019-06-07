#include <stdio.h>

typedef void (*ALLTITUDE)(char,int); // a pointer to function

void getout_male(char gender, int money)
{
    printf("A poor %c  with $%d can't afford anything here\n", gender, money);
} 

void getout_female(char gender, int money)
{
    printf("A poor %c  with $%d can't afford anything here\n", gender, money);
}

void welcome_male(char gender, int money)
{
    printf("Rich %c with %d, you can buy anything!\n", gender, money);
}

void welcome_female(char gender, int money)
{
    printf("Rich %c with %d, you can buy anything!\n", gender, money);
}

ALLTITUDE judge(char gender, int money)
{
    if (gender == 'M')
    {
        if (money < 10000)
        {
            return getout_male;
        }
        else
        {
            return welcome_male;
        }
    }
    else if (gender == 'F')
    {
        if (money < 5000)
        {
            getout_female;
        }
        else
        {
            welcome_female;
        }
    }

}

void new_costumer(char gender, int money)
{
    ALLTITUDE result;
    result = judge(gender, money);
    result(gender, money);
}


int main()
{
    new_costumer('M', 3000);


    return 0;
}