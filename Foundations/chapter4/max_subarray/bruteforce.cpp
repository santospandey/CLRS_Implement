// By brute force method.
#include <iostream>

int main()
{
    int arr[] = {5, -13, 5, 20, -3, -16, 23, -18, 20};
    int len = sizeof(arr) / sizeof(arr[0]);

    int start = -1;
    int end = -1;
    int sum = -999999;

    for (int i = 0; i < len; i++)
    {
        int s = 0;
        for (int j = i; j < len; j++)
        {
            s += arr[j];
            if (s > sum)
            {
                sum = s;
                start = i;
                end = j;
            }
        }
    }

    std::cout << "start = " << start << "\n";
    std::cout << "end = " << end << "\n";
    std::cout << "sum = " << sum << "\n";
    return 0;
}