N = int(input())
M = int(input())

S = []
P = []
for i in range(N):
    line = input()
    S.append(int(line.split(' ')[0]))
    P.append(int(line.split(' ')[1]))

queue = [[M, 0]]
queueStart = 0
queueLast = 0
maxS = 0

newQueueLast = queueLast
for i in range(N):
    for j in range(queueStart, queueLast+1):
        k = 0
        while k * P[i] <= queue[j][0]:
            queue.append([queue[j][0] - k * P[i], queue[j][1] + k * S[i]])
            newQueueLast += 1
            if queue[j][1] + k * S[i] > maxS:
                maxS = queue[j][1] + k * S[i]
            k += 1
        
    queueStart = queueLast
    queueLast = newQueueLast
    
print(maxS)