#include "p_queue.h"

PriorityQueue::PriorityQueue() {}

void PriorityQueue::insert(int key)
{
    arr.resize(arr.size() + 1);
    arr[arr.size() - 1] = -99999;
    increaseKey(arr.size() - 1, key);
}

void PriorityQueue::increaseKey(int i, int key)
{
    if (key < arr.at(i))
    {
        std::cout << "Error key should be greater than current index value";
        return;
    }
    arr[i] = key;
    while (i > 0 && (arr[parent(i)] < arr[i]))
    {
        int temp = arr[i];
        arr[i] = arr[parent(i)];
        arr[parent(i)] = temp;
        i = parent(i);
    }
}

int PriorityQueue::extractMaximum()
{
    if (arr.size() < 1)
    {
        std::cout << "Empty array";
        return -1;
    }
    int max = arr[0];
    arr[0] = arr[arr.size() - 1];
    arr.resize(arr.size() - 1);
    maxHeapify(0);
    return max;
}

void PriorityQueue::maxHeapify(int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (arr[l] > arr[i] && l < arr.size())
    {
        largest = l;
    }
    if (arr[r] > arr[largest] && r < arr.size())
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(largest);
    }
}

int PriorityQueue::parent(int index)
{
    return (index - 1) / 2;
}

int PriorityQueue::maximum()
{
    return arr[0];
}

void PriorityQueue::display()
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

