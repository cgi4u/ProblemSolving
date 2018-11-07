line = input()
N = int(line.split(' ')[0])
M = int(line.split(' ')[1])

queue = [i for i in range(1, N+1)]
#print(queue)

curIdx = 0
moveNeeded = 0

line = input()
for i in range(M):
    delIdx = 0
    nextDel = int(line.split(' ')[i])
    for j in range(N-i):
        if queue[j] == nextDel:
            delIdx = j
            
    moveNeeded += min(abs(delIdx - curIdx), delIdx + ((N-i) - curIdx), curIdx + ((N-i) - delIdx))
    #print(moveNeeded)
    
    del queue[delIdx]
    curIdx = delIdx
    
print(moveNeeded)