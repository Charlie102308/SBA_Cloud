#include <stdio.h>
#include <stdlib.h>
FILE *fp;
char name[32], tel[9];
int i, record;
int main()
{
    fp = fopen("c:\\someinfo.txt", "w");
    printf("How many record:");
    scanf("%d",&record);
    fflush(stdin);
    for(i = 1;i <= record;i++)
    {
        printf("Name:");
        gets(name);
        fprintf(fp, "%s\n", name);
        printf("Tel:");
        gets(tel);
        fprintf(fp, "%s\n", tel);
    }
    fclose(fp);
    return 0;
}