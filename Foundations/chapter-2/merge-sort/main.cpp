#include <iostream>
#include <math.h>

void merge(int *arr, int start, int end)
{
    int mid = (start + end) / 2;
    int arr1[mid - start + 1] = {};
    int arr2[end - mid] = {};

    int index = 0;
    for (int i = start; i <= mid; i++)
    {
        arr1[index] = arr[i];
        index++;
    }

    index = 0;
    for (int i = mid + 1; i <= end; i++)
    {
        arr2[index] = arr[i];
        index++;
    }

    int i = 0;
    int j = 0;
    int k = start;
    int arr1Len = mid-start+1;
    int arr2Len = end-mid;    

    while ((i < arr1Len) && (j < arr2Len))
    {
        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < arr1Len)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < arr2Len)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void divide(int *arr, int startIndex, int endIndex)
{
    if (startIndex == endIndex)
    {
        return;
    }

    int midIndex = ceil((startIndex + endIndex) / 2);
    divide(arr, startIndex, midIndex);
    divide(arr, midIndex + 1, endIndex);

    merge(arr, startIndex, endIndex);
}

int main(int argc, char **argv)
{
    int numbers[] = {36,23,40,26,55,12,89,71,81,23,6,68,56,91,32};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    divide(numbers, 0, length - 1);

    for (int i = 0; i < length; i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";

    return 0;
}