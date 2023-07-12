#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fp;
int i = 0, n, j;
char name[4][32], tel[4][10];
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
    fclose(fp);
    for(j = 1;j < 4;j++)
    {
        printf("%d %s %s\n", j, name[j], tel[j]);
    }
    printf("Which record do you want to change:");
    scanf("%d",&n);
    fflush(stdin);
    printf("New %s tel:",name[n]);
    gets(tel[n]);
    fp = fopen("c:\\record.txt", "w");
    for(j = 1;j < 4;j++)
    {
        fprintf(fp, "%s\n", name[j]);
        fprintf(fp, "%s\n", tel[j]);
    }
    fclose(fp);
    printf("Edit Success");
    return 0;
}