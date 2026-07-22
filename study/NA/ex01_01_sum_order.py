sum1 = 1.0
sum2 = 0.0

dif = 1 / (10 ** 16)
for i in range(1, 10 ** 7):
    sum1 = sum1 + dif
    sum2 = sum2 + dif

sum2 = sum2 + 1.0
print(sum1)
print(sum2)