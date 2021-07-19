a,b,c = map(int, input().split())
n = (c-b)/(a-b)
int_n = int(n)
if int_n < n:
    print(int_n+1)
else:
    print(int_n)
