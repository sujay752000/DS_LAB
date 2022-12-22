#include <stdio.h>

int main()
{
    int n1, x, n2;
    int i = 0, j = 0, k = 0;

    printf("Enter the size of first array : \n");
    scanf("%d", &n1);

    int arr1[n1];

    for (x = 0; x < n1; x++)
    {
        printf("Enter the value at %d position : \n", i);
        scanf("%d", &arr1[x]);
    }

    printf("First Array is : \n");

    for (x = 0; x < n1; x++)
    {
        printf("%d \t", arr1[x]);
    }

    printf("\nEnter the size of second array : \n");
    scanf("%d", &n2);

    int arr2[n2];

    int n3 = n1 + n2;
    int arr3[n3];

    for (x = 0; x < n2; x++)
    {
        printf("Enter the value at %d position : \n", i);
        scanf("%d", &arr2[x]);
    }

    printf("Second Array is : \n");

    for (x = 0; x < n2; x++)
    {
        printf("%d \t", arr2[x]);
    }


    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }

        else
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }

    printf("\nThe merged array is : \n");

    for (x = 0; x < n3; x++)
    {
        printf("%d \t", arr3[x]);
    }

    return 0;
}