#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char source[]="Ricardo Milos was born on November 11, 1977, along with his twin brother, in Rio, Brazil. He is mixed, with both Brazilian and Irish heritage. However, he and his brother are adopted, with a Greek father and a Canadian mother.";
    char str[32], input[32];
    int count = 0, i = 0;
	printf("Enter a word:");
	gets(input);
	while(i < sizeof(source))
	{
		strncpy(str, source + i, strlen (input));
		str[strlen(input)] = '\0';
		if(strcmp(str, input) == 0)
		{
			count ++;
		}
		i++;
		
	}
	if(count > 0)
	{
		printf("Search result: found.  Number of instance %d\n", count);
	}
	else
	{
		printf("Search result: NOT found.");
	}
	return 0;
}
