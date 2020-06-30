#include<iostream>

void printElems(int* arr, int len){    
    for(int i=0; i<len; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

inline void exchange(int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int* arr, int start, int end){
    int x = arr[end];
    int i = start-1;
    for(int j=start; j<=end-1; j++){
        if(arr[j]<x){
            i = i+1;
            exchange(arr, i, j);
        }
    }
    exchange(arr, end, i+1);
    return i+1;
}

void quickSort(int* arr, int start, int end){
    if(start < end){
        int mid = partition(arr, start, end);
        quickSort(arr, start, mid-1);
        quickSort(arr, mid+1, end);
    }
}

int main(){
    int arr[]={56, 75, 33, 42, 20, 61, 9, 50};
    int length = sizeof(arr)/sizeof(arr[0]);    

    quickSort(arr, 0, length-1);
    printElems(arr, length);

}