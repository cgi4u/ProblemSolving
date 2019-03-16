N = int(input())

maxPay = [0 for _ in range(N)]

for i in range(N):
    line = input();
    
    time = int(line.split(" ")[0])
    pay = int(line.split(" ")[1])
    
    #현재 시간 전까지 가능한 최고 보수 + 현재 작업 보수 = 현재 작업이 끝나고 받을 수 있는 최고 보수
    curMaxPay = pay
    if i != 0:
        curMaxPay += maxPay[i-1]
    
	#현재 작업이 끝나고 난 후의 보수가 최대 보수가 되는 모든 시점에 대해 업데이트
    for j in range(i - 1 + time, N):
        if maxPay[j] < curMaxPay:
            maxPay[j] = curMaxPay
        else: break
    
#시간이 모두 경과되었을 때의 최대보수 출력
print(maxPay[N-1])