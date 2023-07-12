#include <stdio.h>
#include <stdlib.h>
int main()
{
    int mark[6], max_mark, min_mark, sum, pass_num, i;
    float mean;
    pass_num = 0;
    max_mark = 0;
    min_mark = 100;
    sum = 0;
    for(i = 1; i <= 5; i++)
    {
        printf("Enter your mark:");
        scanf("%d",&mark[i]);
        sum = sum + mark[i];
        if(mark[i] > max_mark)
        {
            max_mark = mark[i];
        }
        if(mark[i] < min_mark)
        {
            min_mark = mark[i];
        }
        if(mark[i] >= 40)
        {
            pass_num++;
        }
    }
    mean = (float)sum / 5;
    printf("max mark:%d \nmin mark:%d\n", max_mark, min_mark);
    printf("Average mark:%0.2f \nNumber of student pass:%d",mean, pass_num);
    return 0;
}