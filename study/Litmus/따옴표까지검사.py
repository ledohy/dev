def check_matching(text):
    stack = []
    bracket_count = 0

    in_single = False
    in_double = False
    in_comment = False

    pair = {
        ')': '(',
        '}': '{',
        ']': '['
    }

    for ch in text:
        if in_comment:
            if ch == '\n':
                in_comment = False
            continue

        if in_single:
            if ch == "'":
                in_single = False
            continue

        if in_double:
            if ch == '"':
                in_double = False
            continue

        if ch == '#':
            in_comment = True
        elif ch == "'":
            in_single = True
        elif ch == '"':
            in_double = True
        elif ch in '([{':
            stack.append(ch)
        elif ch in ')]}':
            if not stack or stack[-1] != pair[ch]:
                print(f"Error, bracket_count : {bracket_count}")
                return
            stack.pop()
            bracket_count += 1

    if stack:
        print(f"Error, bracket_count : {bracket_count}")
    else:
        print(f"OK, bracket_count : {bracket_count}")


n = int(input())
text = ""
for i in range(n):
    line = input()
    text += line + '\n'

check_matching(text)