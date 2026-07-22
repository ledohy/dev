x = int(input())
y = int(input())

lc = 1

if y > 0:
    if x > 0:
        lc = 1
    else:
        lc = 2
else : 
    if x < 0:
        lc = 3
    else:
        lc = 4
        
print(lc)