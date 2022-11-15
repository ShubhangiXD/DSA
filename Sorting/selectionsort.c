#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void selection(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
}

void insertion(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int k = arr[i];
        for (int j = i - 1; j >= 0 && k < arr[j]; j--)
            arr[j + i] = arr[j];
        arr[i + 1] = k;
    }
}

void merge(int arr[], int low, int up)
{
    int mid;
    int tmp[SIZE];
    if (low < up)
    {
        mid = (low + up) / 2;
        
    }
}