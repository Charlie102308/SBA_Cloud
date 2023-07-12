#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, flag;
    for(i = 1;i <= 100;i++)
    {
        flag = 0;
        if(i % 3 == 0)
        {
            flag = 1;
            if(i % 5 == 0)
            {
                flag = 3;
            }
        }
        else if(i % 5 == 0)
        {
            flag = 2;
        }
        if(flag == 1)
        printf("Fizz\n");
        else if(flag == 2)
        printf("Buzz\n");
        else if(flag == 3)
        printf("FizzBuzz\n");
    }
}