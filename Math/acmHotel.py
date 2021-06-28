testCase = int(input())
while testCase!=0 :
    h, w, customer = map(int, input().split())
    if h > customer:
        back = 1
    else:
        back = customer/h
        if back > int(back):
            back = int(back)+1


    if customer % h == 0 :
        front = h
    else:
        front = customer % h

    print(int(front*100 + back))
    testCase -= 1


#2번이나 틀림