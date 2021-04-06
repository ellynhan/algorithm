numberOfCity = int(input())
distances = list(map(int, input().split()))
prices = list(map(int, input().split()))

budget  = 0
minCost = prices[0]+1
for i in range(numberOfCity-1):
    if prices[i] * distances[i] < minCost * distances[i]:
        minCost = prices[i]
        budget += prices[i] * distances[i]
    else:
        budget += minCost * distances[i]

print(budget)
