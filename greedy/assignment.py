import sys
assignments = []
N = int(sys.stdin.readline().rstrip())
i = 0
while i<N:
    i+=1
    dueDate, score = map(int, sys.stdin.readline().rstrip().split())
    assignments.append([dueDate, score])

assignments.sort(key = lambda x:x[0], reverse=True)

leftDay = assignments[0][0]
maxScore = 0
maxIndex = 0
totalScore = 0
while leftDay !=0 :
    index = 0
    for i in range(int(N)):
        if assignments[i][0] >= leftDay:
            if maxScore < assignments[index][1]:
                maxScore = assignments[index][1]
                maxIndex = index
        index += 1
    totalScore += maxScore
    assignments[maxIndex][0] = 0
    maxScore = 0
    leftDay -= 1

print(totalScore)
