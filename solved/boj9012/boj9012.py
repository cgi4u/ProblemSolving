T = int(input())

for _ in range(0, T):
    line = input()
    
    level = 0
    for i in range(0, len(line)):
        if line[i] != '(' and line[i] != ')':
            level = -1
            break

        if line[i] == '(':
            level += 1
        else:
            level -= 1
            if level < 0:
                break

    if level == 0:
        print("YES")
    else:
        print("NO")


