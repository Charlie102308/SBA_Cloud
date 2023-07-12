#include <stdio.h>
int main()
{
    float Fahrenheit, Celsius;
    printf("Enter Temp in C:");
    scanf("%f",&Celsius);
    Fahrenheit = Celsius * 9 / 5 + 32;
    printf("The temp is %0.1f degree F",Fahrenheit);
    return 0;
}