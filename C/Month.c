#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n, source;
    char x[49], month[4];
    strcpy(x, "Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec");
    printf("Enter a number(1 - 12):");
    scanf("%d",&n);
    source = n * 4 - 4;
    month[3] = '\0';
    strncpy(month, x + source, 3);
    printf("The month :%s",month);
    return 0;
}