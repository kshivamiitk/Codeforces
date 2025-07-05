def main():
    tc = int(input())
    for _ in range(tc):
        n = int(input())
        arr = list(map(int, input().split()))
        possible = True

        if n == 2:
            if arr[0] <= 2 or arr[1] <= 2:
                print("NO")
            else:
                print("YES")
            continue

        if arr[0] <= 2 * (n - 1) or arr[n - 1] <= 2 * (n - 1):
            print("NO")
            continue

        for i in range(1, n - 1):
            if arr[i] <= 2 * max(i, n - i - 1):
                possible = False
                break

        if possible:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()