#include <iostream>

int *sort(int *A, int n)
{
    for (int i = 1; i < n; ++i)
    {
        int item = A[i];
        int j = i - 1;
        while (j >= -1 && A[j] > item)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = item;
    }
    return A;
}

void printArray(int *A, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";
}
