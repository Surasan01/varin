import math
def merge(a, b):
    if len(a) == 0:
        return b
    elif len(b) == 0:
        return a
    elif float(a[0][4]) < float(b[0][4]):
        return [a[0]] + merge(a[1:], b)
    else:
        return [b[0]] + merge(a, b[1:])

def mergesort(x):
    if len(x) < 2:
        return x
    else:
        h = len(x) // 2
        return merge(mergesort(x[:h]), mergesort(x[h:]))

def kNN(data, lat, long):
    if len(data) == 0:
        return []
    else:
        k = round(math.sqrt(pow((data[0][1] - lat), 2) + pow((data[0][2] - long), 2)), 2)
        return [data[0] + [k]] + kNN(data[1:], lat, long)

def hasYes(data, n = 0):
    if len(data) == 0:
        if n<2:
            return "No"
        else:
            return "Yes"
    elif data[0][3] == "Yes":
        return hasYes(data[1:], n+1)
    else:
        return hasYes(data[1:], n)

def process(data, lat, long):
    knn = kNN(data, lat, long)
    sorted = mergesort(knn)
    result = hasYes(sorted[0:3])
    return sorted, result

data = [
    [1, 54, 97, "Yes"],
    [2, 99, 91, "No"],
    [3, 61, 53, "Yes"],
    [4, 43, 95, "No"],
    [5, 60, 10, "Yes"],
    [6, 40, 74, "No"],
    [7, 16, 92, "Yes"],
    [8, 8, 8, "No"],
    [9, 90, 37, "Yes"],
    [10, 13, 32, "No"],
    [11, 85, 75, "Yes"],
    [12, 98, 23, "No"],
    [13, 94, 74, "Yes"],
    [14, 54, 38, "No"],
    [15, 36, 42, "Yes"]
]
lat, long = 52, 25

sorted_data, result = process(data, lat, long)
print(data[0:3])
print("(Yes / No)  ? :", result)