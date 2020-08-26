class Item:
    def __init__(self, id, weight, value):
        super().__init__()
        self.id = id
        self.weight = weight
        self.value = value

    def printValue(self):
        print(f"{self.id} {self.weight} {self.value}")


class KnapSack:
    def __init__(self, items, capacity):
        super().__init__()
        self.items = items
        self.capacity = capacity

    def solve(self):
        table = []
        for i in range(0, len(self.items)):
            table.append([])
            for j in range(0, self.capacity+1):
                table[i].append(0)

        for i in range(1, len(self.items)):
            for j in range(0, self.capacity+1):
                if self.items[i].weight > j:
                    table[i][j] = table[i-1][j]
                else:
                    table[i][j] = max(
                        (self.items[i].value + table[i-1][j-self.items[i].weight]),
                        table[i-1][j]
                    )        

        solution = []
        i = len(self.items) - 1
        j = self.capacity
        while i > 0:
            if table[i][j] > table[i-1][j]:
                solution.append(self.items[i])
                j = j - self.items[i].weight
            i = i - 1

        return solution

items = [
    Item(0, 0, 0),
    Item(1, 2, 3),
    Item(2, 3, 5),
    Item(3, 5, 8),
    Item(4, 6, 10)
]

capacity = 12

knapsack = KnapSack(items, capacity)
result = knapsack.solve()
for item in result:
    item.printValue()
