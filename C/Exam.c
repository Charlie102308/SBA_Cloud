#include <stdio.h>
#include <string.h>
int flag = 1,n;
char word[20];
int main()
{
    do {
flag = 1;
    printf("Please input an English word : ");
    scanf("%s",word);
       for(n=0; n<strlen(word); n++)
       {
           if((word[n]<'A' || word[n]>'z') || (word[n] > 'Z' && word[n] < 'a'))
           {
               flag = 0;
           }
       }
       if(flag==0){
         printf("Enter English letters only!");
}
}
while(flag==0);
printf("Good");
}