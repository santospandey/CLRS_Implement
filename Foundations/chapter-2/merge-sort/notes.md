Suppose we have an array = [43, 23, 23, 12, 10, 4, -2, 12]
and we want to sort the array by using merge sort. 
It is based on the paradigm of divide and conquer. 
At first we divide the array into successive halves until when we couldnot further 
divide. That is when an array is divided into each one element array. 
We Then merge each two array from buttom to up fasion in such a way that merged 
array is always sorted. To be more clearly we have to merged two sorted array so that the 
resulted array is itself sorted. 

If we look at the example above

[43, 23, 23, 12, 10, 4, -2, 12]

The divide procudure runs in following way:-
=>  [43, 23, 23, 12], [10, 4, -2, 12]
=>  [43, 23], [23, 12], [10, 4], [-2, 12]
=>  [43], [23], [23], [12], [10], [4], [-2], [12]
It stops when we couldnot further divide such that each array contains elements.


The merge procedure runs in the following way:-
It uses two pointer scanning.
Let's suppose we have two sorted arrays A and B and we want to merge them

Merge(A, B)
    i = 1
    j = 1
    k = 1
    total_length = A.length + B.length
    Create an array C of length total_length

    while((i is Less than A.length) AND (j is Less than B.length)):
        if(A[i] isLessThan A[j]):
            C[k] = A[i]
            i = i+1
        else
            C[k] = B[j]
            j = j+1
        k = k+1;
    
    while(i is Less than A.length):
        C[k] = A[i]
        i = i+1
        k = k+1

    while(j is less than B.length):
        C[k] = B[j]
        j = j+1
        k = k+1
    
    return C


Next Question is how can you recursively divide an array to multiple arrays having single element recursively.

Divide(A, startIndex, endIndex):    
    if(startIndex == endIndex):
        Create an Array result of length 1
        result[1] = A[startIndex]
        return result
    
    midIndex = (startIndex + endIndex)/2
    Divide(A, startIndex, midIndex)
    Divide(A, mideIndex+1, endIndex)
    
        