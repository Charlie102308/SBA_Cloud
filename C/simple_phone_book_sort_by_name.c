#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fp;
int i = 0, n, j;
char name[4][32], tel[4][10];
int pass, comp;
int main(){
    fp=fopen("c:\\someinfo.txt", "r");
    while(!feof(fp))
    {
        i++;
        fgets(name[i], 33, fp);
        name[i][strlen(name[i]) - 1] = '\0';
        fgets(tel[i], 10, fp);
        tel[i][strlen(tel[i]) - 1] = '\0';
    }
    fclose(fp);
    printf("Before sort by name\n");
    for(j = 1;j < 4;j++)
    {
        printf("%d %s %s\n", j, name[j], tel[j]);
    }
    for(pass = i - 2;pass >= 1;pass--)
    {
        for(comp = 1;comp <= pass;comp++)
        {
            if(strcmp(name[comp],name[comp + 1]) > 0)
            {
                strcpy(name[0],name[comp]);
                strcpy(name[comp],name[comp + 1]);
                strcpy(name[comp + 1],name[0]);
                strcpy(tel[0],tel[comp]);
                strcpy(tel[comp],tel[comp + 1]);
                strcpy(tel[comp + 1],tel[0]);
            }
        }
    }
    printf("After sort by name\n");
    for(j=1; j<=i-1; j++)
    {
        printf("%d %s %s\n", j, name[j], tel[j]);
    }
    return 0;
}
