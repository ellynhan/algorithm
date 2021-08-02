import sys
n=int(sys.stdin.readline())
c = [0] * 10001
for i in range(n):
    tmp = int(sys.stdin.readline())
    c[tmp] += 1;

for i in range(10001):
    for j in range(c[i]):
        print(i)