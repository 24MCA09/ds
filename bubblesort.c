#include <stdio.h>

// function bubble sort Array
void bubble_sort_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("The sorted Array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}

// main function
void main()
{
    int n = 5, choice, i;
    int arr[n];

    printf("Enter the Size of the Array : ");
    scanf("%d", &n);

    printf("\nEnter the Array elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubble_sort_array(arr, n);
    printf("\n");
}
