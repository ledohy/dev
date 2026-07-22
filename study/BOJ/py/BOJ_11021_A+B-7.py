T = int(input())

for i in range(1, T+1):
    a, b = map(int, input().split())
    sum = a + b
    print(f"Case #{i}: {sum}")