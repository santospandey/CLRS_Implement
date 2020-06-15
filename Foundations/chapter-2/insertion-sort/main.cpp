#include <iostream>
#include "insertion.h"

int main()
{
    int arr[] = {5, 3, 1, 8, 6};
    int length = sizeof(arr) / sizeof(arr[0]);
    int *result = sort(arr, length);

    printArray(result, length);
    
    return 0;
}