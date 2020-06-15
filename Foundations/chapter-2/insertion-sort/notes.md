# Insertion Sort:-
    Just Like playing card sorting, Keep first card as it is and from card 2 to all other
    consequent cards pick the card and let it's be "k" and inset it to its proper position 
    which result the cards from 1 to k-1 to be sorted. 

## Algorithm:-

Insertion-Sort(A):
    n = A.length

    for i=2 to n:
        item = A[i]
        k = i-1
        while(k>0 && A[k]>item):
            A[k+1] = A[k]
            k = k-1        
        A[k+1] = item
        
    return A




