n1, n2, n3 = map(int, input().split())

ec = 0 # equal_count, 같은 숫자 '관계'의 갯수
dice = 0 #같은 눈이 나오면 눈이 몇인지 저장

if n1 == n2:
    ec += 1
    dice = n1
if n2 == n3:
    ec += 1
    dice = n2
if n1 == n3:
    ec += 1
    dice = n3
    
prize = 0

if ec == 0:
    prize += max(n1, n2, n3) * 100
elif ec == 1:
    prize += 1000 + dice * 100
elif ec == 3:
    prize += 10000 + dice * 1000
    
print(prize)