#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fp;
int i = 0, last, j;
char name[4][32], tel[4][10];
int pass, comp;
int main()
{
    fp=fopen("c:\\someinfo.txt", "r");
    while(!feof(fp))
    {
        i++;
        fgets(name[i], 33, fp);
        name[i][strlen(name[i]) - 1]='\0';
        fgets(tel[i], 10, fp);
        tel[i][strlen(tel[i]) - 1]='\0';
    }
    fclose(fp);
    if(fp == NULL)
    {
		printf("Cannot open the file.");
		return 0;
	}
    printf("Before sort by name\n");
    for(j=1; j<=i-1; j++)
    {
        printf("%d %s %s\n", j, name[j], tel[j]);
    }
    for(pass = 2;pass <= i - 1;pass++)
    {
        strcpy(name[0], name[pass]);
        strcpy(tel[0], tel[pass]);
        last = pass - 1;
        while(strcmp(name[0], name[last]) < 0 && last >= 1)
        {
            strcpy(tel[last + 1], tel[last]);
            strcpy(name[last + 1], name[last]);
            last--;
        }
        strcpy(name[last + 1], name[0]);
        strcpy(tel[last + 1], tel[0]);
    }
    printf("After sort by name\n");
    for(j=1; j<=i-1; j++)
    {
        printf("%d %s %s\n", j, name[j], tel[j]);
    }
    return 0;
}
