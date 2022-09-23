def main():
    T = int(input())

    while T:
        T -= 1
        ct = 1
        s, t, i = map(int, input().split())
        if s <= i and i <= t:
            print(s, t)
            while s != t:
                if t-i < i-s:
                    s = s + int((t-s)/2) + 1
                    ct += 1
                    print(s, t)
                else:
                    t = s + int((t-s)/2)
                    ct += 1
                    print(s, t)
            print(ct)
        else:
            print(-1)
      
      
if __name__ == "__main__":
    main()