#include <stdio.h>
#include <stdlib.h>
int main()
{
    char grade;
    do
    {
        printf("grade(a/A/b/B/c/C):");
        fflush(stdin);
        scanf("%c",&grade);
        if(grade != 'a' && grade != 'A' && grade != 'b' && grade != 'B' && grade != 'c' && grade != 'C')
        {
            printf("invalid! try again!\n");
        }
    }
    while(grade != 'a' && grade != 'A' && grade != 'b' && grade != 'B' && grade != 'c' && grade != 'C');
    printf("bye");
    return 0;
}