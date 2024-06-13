def find_median(arr):
    arr.sort()  # เรียงข้อมูลเพื่อหาค่ามัธยฐาน
    n = len(arr)
    if n % 2 == 0:
        median = (arr[n // 2 - 1] + arr[n // 2]) / 2  # หาค่ามัธยฐานสำหรับข้อมูลที่มีจำนวนคู่
    else:
        median = arr[n // 2]  # หาค่ามัธยฐานสำหรับข้อมูลที่มีจำนวนคี่
    return median

def find_mode(arr):
    frequency = {}  # สร้างพจนานุกรมเพื่อเก็บความถี่ของแต่ละตัวเลข
    for num in arr:
        if num in frequency:
            frequency[num] += 1
        else:
            frequency[num] = 1
    mode = max(frequency, key=frequency.get)  # หาค่าที่มีความถี่มากที่สุด
    return mode

# ตัวอย่างการใช้งาน
data = [3, 1, 7, 9, 3, 7, 7, 7,9,9,9,9,9,9,9,9, 9, 0, 2, 6, 9, 4, 3, 5, 8, 8, 5, 4, 5, 1, 0, 3, 6, 2, 9, 1, 2, 8, 4, 4, 6, 2, 3, 7, 5, 8, 5, 4, 0, 1, 1, 8, 6, 0, 2, 6, 7, 0, 9, 5, 4, 1, 8, 0, 5, 8, 3, 7, 3, 5, 0, 7, 9, 8, 5, 8, 0, 1, 7, 7, 5, 6, 4, 5, 4, 2, 9, 2, 4, 9, 7, 2, 4, 3, 0, 4, 3, 1, 7, 9, 3, 6, 3, 7, 9, 0, 8, 8, 8]
print("Median:", find_median(data))
print("Mode:", find_mode(data))
