while True:
    try:
        a, b = map(int, input().split())
        print(a+b)
    except:
        #EOFError is caught from input()
        break