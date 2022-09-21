#include <stdio.h>
void main()
{
    float year1[12];
    float year2[12];
    printf("Enter the data:\n");
    for (int i = 1; i <= 12; i++)
    {
        float y1, y2;
        printf("Enter the data for month %d in the first year: \n", i);
        scanf("%f", &y1);
        year1[i] = y1;
        printf("Enter the data for month %d in the second year: \n", i);
        scanf("%f", &y2);
        year2[i] = y2;
        y1 = 0;
        y2 = 0;
    }
    float total1;
    float avg1;
    // display
    printf("Table of monthly rainfall: \n");
    printf("\t January \t February \t March \t\t April \t\t May \t\t June \t\t July \t\t August \t September \t October \t Novemeber \t December \n");
    printf("Year 1 \t");
    for (int i = 1; i <= 12; i++)
    {
        printf("%.3f \t\t", year1[i]);
        total1 = total1 + year1[i];
    }
    avg1 = total1 / 12;
    printf("\n");
    float total2;
    float avg2;
    printf("Year 2 \t");
    for (int i = 1; i <= 12; i++)
    {
        printf("%.3f \t\t", year2[i]);
        total2 = total2 + year2[i];
    }
    avg2 = total2 / 12;
    printf("\nThe total rainfall for present year: %.3f", total1);
    printf("\nThe total rainfall for last year: %.3f", total2);
    printf("\nThe average rainfall for present year: %.3f", avg1);
    printf("\nThe average rainfall for last year: %.3f", avg2);
}