#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i, Time, num[Time];
    srand(time(0));
    printf("how many time:");
    scanf("%d",&Time);
    for(i = 1;i <= Time;i++)
    {
        num[i] = rand() % 26 + 1;
        printf("%d\n", num[i]);
    }
    return 0;
}