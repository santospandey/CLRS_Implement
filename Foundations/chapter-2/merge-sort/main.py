from math import floor

class MergeSort:    
    POSITIVE_INFINITY = 9999999999

    def __init__(self, data, ch):
        super().__init__()        
        if self.isList(data):
            self.data = data
        if ch:
            MergeSort.POSITIVE_INFINITY = '}'


    def isList(self, data):
        return isinstance(data, list)


    def set_data(self, data):
        if self.isList(data):
            self.data = data


    def sort(self):
        start = 0
        end = len(self.data) - 1
        if start <= end:
            self.merge(start, end)
        else:
            print("enter array of least size 1")

    def merge(self, start, end):
        if(start == end):
            return

        mid = floor((start + end)/2)

        self.merge(start, mid)
        self.merge(mid+1, end)
        self.combine(start, mid, end)


    def combine(self, start, mid, end):
        first_arr = self.data[start:mid+1]
        second_arr = self.data[mid+1: end+1]

        # Add guards to both arrays
        first_arr.append(MergeSort.POSITIVE_INFINITY)
        second_arr.append(MergeSort.POSITIVE_INFINITY)

        i = 0
        j = 0
        k = start
        while k <= end:
            if first_arr[i] < second_arr[j]:
                self.data[k] = first_arr[i]
                i = i+1
            else:
                self.data[k] = second_arr[j]
                j = j + 1

            k = k + 1


    def print(self):        
        for num in self.data:
            print(num, end = " ")
        print()


arr = ['h','e','l','l','o']
merge_sort = MergeSort(arr, ch=True)
merge_sort.sort()
merge_sort.print()
