name = [''] * 10
sum_scores = 0
score = [0] * 10
i = 0

while True:
    name[i] = input("name : ")
    if name[i][0] == '*':
        break
    score[i] = int(input("score : "))
    sum_scores += score[i]
    i += 1

mean = sum_scores / (i)

max_mark = 0
max_score = 0

for j in range(i):
    if score[j] > max_score:
        max_score = score[j]
        max_mark = j

print("mean =", mean)
print("max name =", name[max_mark])
print("max score =", score[max_mark])
