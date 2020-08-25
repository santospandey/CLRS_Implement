# finding maxsubarray
def calculate_max_sum(arr):

    length = len(arr)

    data = {
        "low": 0,
        "high": 0,
        "sum": 0
    }

    for i in range(length):
        j = i
        sum = 0
        while j < length:
            sum = sum + arr[j]
            if sum > data["sum"]:
                data["sum"] = sum
                data["low"] = i
                data["high"] = j
            j = j + 1

    return data


arr = [2, -4, 2, 3, 5, -8, -2, 5, 10]
print(calculate_max_sum(arr))
