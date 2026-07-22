def check_matching(text):
    stack = []
    brk = 0; success = True
    lc = 0
    for char in text:
        if char == '\n':
            lc += 1
        elif char in "({[":
            stack.append(char)
        elif char in ")}]":
            if not stack:
                success = False
                break
            top = stack.pop()
            if (char == ")" and top != "(") or (char == "}" and top != "{") or (char == "]" and top != "["):
                success = False
                break
            brk += 1
    if success and not stack:
        print("OK,", end=' ')
    else:
        print("ERROR,", end=' ')
    print("line_count : {lc}, bracket count : {brk}".format(lc=lc, brk=brk))

n = int(input())
text = ""
for i in range(n):
    line = input()
    text += line + '\n'
check_matching(text)