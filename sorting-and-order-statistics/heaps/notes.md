# Heaps
It is data structure in which the elements are represented in array. It holds certain 
property. If an element is in ith place of array its children should be 2*i+1 and 2*i+2 
places. 
For example
                        68
                        /\
                       /  \
                      8    23
                     / \   /\
                    6   9 13 34

                    Can be represented in array structure as 
[68, 8, 23, 6, 9, 13, 34]

There are two kinds of heaps in both of which the value in node satisfies the certain properties. 
i. Max Heap => A[Parent[i]] >= A[Child[i]]
    The largest element of max heap is its root.

ii. Min Heap => For every node other than parent node A[Parent[i]] <= A[Child[i]]
    The smallest element of min heap is its root. 

For heap sort algorithm we use max heap. Min heap are used for priority queue.

Maintaining Heap Property:-
Its input are array A and index i. It assume that element on i index may voilate max heap property but it's children follow max heap property i.e LEFT(i) and RIGHT(i) are max heap
tree itself.

    MAX_HEAPIFY(A, i)
        l = LEFT(i)
        r = RIGHT(i)
        largest = i
        if((A[l] > A[i]) and (l <= A.size)):
           largest = l         
        if((A[r] > A[largest]) and (r <= A.size)):
           largest = r
        
        if(largest != i):        
            exchange A[i] with A[largest]
            MAX_HEAPIFY(A, largest)


Building a Heap:-
    
    BUILD_MAX_HEAP(A)
        for(i = A.length/2 down to 1):
            MAX_HEAPIFY(A, i)