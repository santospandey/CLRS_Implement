/* #include<iostream>

int recursiveSum(int* arr, int start, int end){
    if(start==end){
        return arr[start];
    }

    int mid = (start+end)/2;
    
    return recursiveSum(arr, start, mid) + recursiveSum(arr, mid+1, end);
}

int main(){

    int arr[] = {34, 23, 45, 676, 12, -98, -43};
    int len = sizeof(arr)/sizeof(arr[0]);

    int result = recursiveSum(arr, 0, len-1);
    std::cout<<"result = "<<result<<"\n";

    return 0;
}
*/

#include <iostream>
#include <string>

int calculateSum(int* arr, int index, int size, int sum){
    if(index == size){
        return sum;
    }
    sum += arr[index];    
    return calculateSum(arr, ++index, size, sum);
}

int main()
{
  int arr[] = {34, 55, 78, 123, 32, -9, 56};
  int len = sizeof(arr)/sizeof(arr[0]);
  int result = calculateSum(arr, 0, len, 0);
  std::cout<<"result "<<result<<"\n";
  return 0;
}

