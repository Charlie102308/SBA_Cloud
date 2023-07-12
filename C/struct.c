#include <stdio.h>
#include <string.h>
int i = 1, flag = 1, n;
char reply;
struct Contract_person_book
{
	char name[5][32], contract[5][32];
	int phone_num[5];
};
void GetInfo(struct Contract_person_book *Book);
void PrintInfo(struct Contract_person_book *Book);
int main()
{
	struct Contract_person_book Book;
	while(i < 5 && flag == 1)
	{
		GetInfo(&Book);
		PrintInfo(&Book);
		printf("Anymore (y/n):");
		scanf("%c",&reply);
		fflush(stdin);
		if (reply == 'n')
		{
			flag = 0;
			printf("End");
		}
		i++;
	}
}
void GetInfo(struct Contract_person_book *Book)
{
	printf("Name:");
	fgets(Book->name[i], 32, stdin);
	printf("Contract person:");
	fgets(Book->contract[i], 32, stdin);
	printf("Phone number:");
	scanf("%d",&Book->phone_num[i]);
	fflush(stdin);
}
void PrintInfo(struct Contract_person_book *Book)
{
	for(n = 1;n <= i;n++)
	{
		printf("%d:", n);
		printf("%s", Book->name[n]);
		printf("Contract person:%s",Book->contract[n]);
		printf("Telphone number:%d\n",Book->phone_num[n]);
	}
}