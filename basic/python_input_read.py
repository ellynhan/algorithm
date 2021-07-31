import sys
n=int(sys.stdin.readline())
arr = []
while n !=0 :
    n -= 1
    tmp = int(sys.stdin.readline())
    arr.append(tmp)
arr.sort()
for i in arr:
    print(i)

#python에서 input으로 읽는 것 보다 sys.stdin.readline으로 읽는게 더 빠르다. 