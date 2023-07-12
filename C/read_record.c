#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fp;
int i = 0, n, j = 0;
char name[32], tel[9];
int main()
{
    fp = fopen("c:\\record.txt", "r");
    while(!feof(fp))
    {
        i++;
        fgets(name, 33, fp);
        fgets(tel, 10, fp);
    }
    fclose(fp);
    fp = fopen("c:\\record.txt", "r");
    while(!feof(fp))
    {
        j++;
        if(j < i)
        {
            fgets(name, 33, fp);
            name[strlen(name) - 1] = '\0';
            printf("%s\n",name);
            fgets(tel, 10, fp);
            tel[strlen(tel) - 1] = '\0';
            printf("%s\n",tel);
        }
    }
    fclose(fp);

}