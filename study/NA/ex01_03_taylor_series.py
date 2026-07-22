from math import factorial
s = 0
for k in range(0,10):
    s = s + (1) ** k / factorial(k)
    if k % 2 == 0:
        print(s)