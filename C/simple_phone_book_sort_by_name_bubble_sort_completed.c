// simple phone book sort by name bubble sort.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fp;
int i = 0, n, j;
struct phone_book
{
char name[32], tel[10];
};
int pass, comp;
int main(){
    struct phone_book Book[5];
    fp=fopen("c:\\record.txt", "r");
    while(!feof(fp)){
        i++;
        fgets(Book[i].name, 33, fp);
        Book[i].name[strlen(Book[i].name) - 1]='\0';
        fgets(Book[i].tel, 10, fp);
        Book[i].tel[strlen(Book[i].tel) - 1]='\0';
    }
    fclose(fp);

    printf("Before sort by name\n");
    for(j=1; j<=i-1; j++){
        printf("%d %s %s\n", j, Book[j].name, Book[j].tel);
    }

    for(pass=i-1-1; pass>=1; pass--){
		for(comp=1; comp<=pass; comp++){
			if(strcmp(Book[comp].name,Book[comp + 1].name) > 0)
            {
                Book[0] = Book[comp];
                Book[comp] = Book[comp + 1];
                Book[comp + 1] = Book[0];
			}
		}
	}

    printf("After sort by name\n");
    for(j=1; j<=i-1; j++){
        printf("%d %s %s\n", j, Book[j].name, Book[j].tel);
    }
    return 0;
}
