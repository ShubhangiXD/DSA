#include<stdio.h>
#include<stdlib.h>
int main()
{
    float n;
    printf("Enter Richter scale number: \n");
    scanf("%f", &n);
    if(n < 5.0)
        printf("Little or no damage");
    else if(n >= 5.0 && n < 5.5)
        printf("some damage");
    else if(n >= 5.5 && n < 6.5)
        printf("serious damage : walls may crack");
    else
        printf("catastrophe : most buildings destroyed");
    return 0;
}