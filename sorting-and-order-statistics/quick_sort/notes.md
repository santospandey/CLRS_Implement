# Quick Sort:-
Before explaning quick sort let us understand by example.
Suppose we have to sort the following array by using quick sort method

# [56, 75, 33, 42, 20, 61, 9, 50]
=> [(33, 42, 20, 9), 50, (56, 75, 61)] => left side contains all nums greater than 50. 
=> [((9), (33, 42, 20)), 50, ((56), 61, (75))]
=> [9, 20, 33, 42, 50, 56, 61, 75]


At first we choose the last element and partition the array into two subarray
such that the last element bisect the array into two partitions such that element
that are in left side are less than or equal to it and element to its right side are 
greater. 
The element 50 got its position or properly sorted and to sort other elements we recursively person same operation to left subarray and right subarray until all the elements are sorted.


But how to formulate an algorithm ???
