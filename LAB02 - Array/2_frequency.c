#include <stdio.h>
int main()
{
    int len;
    printf("Enter the length of the array: \n");
    scanf("%d", &len);

    int arr[len], i = 0;

    printf("Enter the elements of the array: \n");
    while (i < len)
    {
        scanf("%d", &arr[i]);
        i++;
    }
    i = 0;
    int count = 1, min = 0, j = 0, count_min = len;
    while (i < len)
    {
        j = 0;
        count = 1;
        while (j < len)
        {
            // printf("%d\n",count);
            if (arr[j] == arr[i])
            {
                count++;
            }
            j++;
        }
        if (count < count_min)
        {
            count_min = count;
            min = arr[i];
        }
        i++;
    }

    printf("The least frequent number is %d, which is repeating at a frequency of: %d times", min, count_min - 1);

    return 0;
}