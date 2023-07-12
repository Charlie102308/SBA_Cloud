#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fp;
int i = 0, j, n = 0, flag = 1;
char name[4][32], tel[4][10], search[32];
int main()
{
    fp = fopen("c:\\record.txt", "r");
    while(!feof(fp))
    {
        i++;
        fgets(name[i], 33, fp);
        name[i][strlen(name[i]) - 1] = '\0';
        fgets(tel[i], 10, fp);
        tel[i][strlen(tel[i]) - 1] = '\0';
    }
    printf("What do want to search:");
    gets(search);
    while(flag == 1 && n < 4)
    {
        if(strcmp(search, name[n]) == 0)
        {
            flag = 0;
        }
        else if(strcmp(search, tel[n]) == 0)
        {
            flag = 0;
        }
        else
        {
            n++;
        }
    }
    if(flag == 0)
    {
        printf("Tel no. of %s is %s\n", name[n], tel[n]);
    }
    else
    {
        printf("Result: Not Found.");
    }
    fclose(fp);
    return 0;
}