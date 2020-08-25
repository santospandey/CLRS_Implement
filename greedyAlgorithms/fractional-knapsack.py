# Reference:- Ghassan Shobaki Computer Science Lectures video
# Algorithms Lecture 14: Greedy Algorithms, Knapsack Problem

class Item:
    def __init__(self, id, value, weight):
        super().__init__()
        self.value = value
        self.weight = weight
        self.id = id
    
    def get_unit_value(self):
        return self.value/self.weight
    
    def printValue(self):
        print(f"{item.id} {item.value} {item.weight}")
    

class SortItem:
    def __init__(self, items, capacity):
        super().__init__()
        self.items = items
        self.capacity = capacity

    def sort(self):
        self.items.sort(key=lambda item: item.get_unit_value(), reverse=True)
    
    def knap_sack(self):
        self.sort()
        load = 0
        sack_list = []
        for item in self.items:
            if (self.capacity - load) >= item.weight:
                sack_list.append(item)
                load += item.weight
            else:
                r_weight = self.capacity - load
                r_value = item.get_unit_value()*r_weight
                remaining_item = Item(item.id, r_value, r_weight)
                sack_list.append(remaining_item)
                break

        return sack_list    


items = [
    Item(1, 60, 10),
    Item(2, 100, 20),
    Item(3, 120, 30)
]

capacity = 50

sort_item = SortItem(items, capacity)
l = sort_item.knap_sack()
for item in l:
    item.printValue()