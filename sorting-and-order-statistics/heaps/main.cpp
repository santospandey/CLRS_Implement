#include <iostream>

int left(int index)
{
    return 2 * index + 1;
}

int right(int index)
{
    return 2 * index + 2;
}

void maxHeapify(int *arr, int index, int size)
{
    int l = left(index);
    int r = right(index);
    int largest = index;
    if ((arr[l] > arr[index]) && (l < size))
    {
        largest = l;
    }
    if ((arr[r] > arr[largest]) && (r < size))
    {
        largest = r;
    }

    if (largest != index)
    {
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, largest, size);
    }
}

void printElements(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void buildMaxHeap(int *arr, int size){
    for(int i=size/2; i>=0; i--){
        maxHeapify(arr, i, size);
    }
}

void heapSort(int *arr, int size){
    int tempSize = size;
    buildMaxHeap(arr, size);    
    for(int i=size-1; i>0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        maxHeapify(arr, 0, --tempSize);
    }
}

int main()
{
    int arr[] = {4,1,3,2,16,9,10,14,8,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    printElements(arr, size);    
    
    heapSort(arr, size);
    printElements(arr, size);    

    return 0;
}