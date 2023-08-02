# keeping books in a shelf of C capacity for the minimum remaining space
def minimum_remaining_space(books, C):
    dp = [0] * (C + 1)
    for i in range(1, C + 1):
        dp[i] = float('inf')
        for book in books:
            if i - book >= 0:
                dp[i] = min(dp[i], dp[i - book] + 1)
    return dp[C]


for _ in range(int(input())):
    n,C = [int(x) for x in input().split()]
    books = [int(x) for x in input().split()]
    print(minimum_remaining_space(books, C))


