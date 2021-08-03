import sys
n=int(sys.stdin.readline())
d = dict()
cnt = 0
arr = []
for i in range(n):
    tmp = int(sys.stdin.readline())
    arr.append(tmp)
    if tmp not in d:
        d[tmp]=1
    else:
        d[tmp]+=1
    cnt += tmp

arr.sort()
mid = arr[int(n/2)]

mf = 0
mf_key = 0
for key, val in d.items():
    if mf < val:
        mf = val
        mf_key = key

cnt3 = 0
arr2 = []
for key, val in d.items():
    if val == mf:
        arr2.append(key)

arr2.sort()
print(round(cnt/n))
print(mid)
if len(arr2)>1:
    print(arr2[1])
else:
    print(arr2[0])
print(arr[n-1]-arr[0])

