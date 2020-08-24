from math import floor

class MergeSort:    
    POSITIVE_INFINITY = 9999999999

    def __init__(self, data):
        super().__init__()
        if self.isList(data):
            self.data = data


    def isList(self, data):
        return isinstance(data, list)


    def set_data(self, data):
        if self.isList(data):
            self.data = data


    def sort(self):
        start = 0
        end = len(self.data) - 1
        self.merge(start, end)
    

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


arr = [18, 4, 36, 12, 1, 9, 23]
merge_sort = MergeSort(arr)
merge_sort.sort()
merge_sort.print()
