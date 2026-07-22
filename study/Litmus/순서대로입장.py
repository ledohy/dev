N = int(input())
arr = list(map(int, input().split()))

stack = []
want = 1

for x in arr:
    if x == want:
        want += 1
    else:
        stack.append(x)

    while stack and stack[-1] == want:
        stack.pop()
        want += 1

if want == N + 1:
    print("OK")
else:
    print("NO")