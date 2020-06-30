#include <iostream>

int max(int n1, int n2, int n3)
{
    int temp = n1 > n2 ? n1 : n2;
    return n3 > temp ? n3 : temp;
}

int maxCrossing(int *arr, int start, int end, int mid)
{
    int leftSum = -99999;
    int rightSum = -99999;
    int tempSum = 0;
    int index = mid;    
    while (index >= start)
    {
        tempSum += arr[index];
        if (tempSum > leftSum)
        {
            leftSum = tempSum;
        }
        index--;
    }
    index = mid + 1;
    tempSum = 0;
    while (index <= end)
    {
        tempSum += arr[index];
        if (tempSum > rightSum)
        {
            rightSum = tempSum;
        }
        index++;
    }
    return leftSum + rightSum;
}

int maxSum(int *arr, int start, int end)
{

    if (start == end)
    {
        return arr[start];
    }

    int mid = (start + end) / 2;
    int n1 = maxSum(arr, start, mid);

    int n2 = maxSum(arr, mid + 1, end);

    int n3 = maxCrossing(arr, start, end, mid);

    return max(n1, n2, n3);
}

int main()
{
    int arr[] = {5, -13, 5, 20, -3, -16, 23, -18, 20};
    int len = sizeof(arr) / sizeof(arr[0]);
    int result = maxSum(arr, 0, len - 1);
    std::cout << "sum = " << result<<"\n";
    return 0;
}