rods = [12, 15]
costs = [2, 3]
cut_pieces = [6,6,6,6,6,6,6,6]
cut_pieces.sort(reverse=True)
n = len(cut_pieces)

# create a 2D table to store minimum costs
# dp[i][j] represents the minimum cost to cut pieces from 0 to i using rods j and j+1
dp = [[float('inf')] * 2 for _ in range(n)]

# initialize the base case
for i in range(2):
    for j in range(n):
        if cut_pieces[j] <= rods[i]:
            dp[j][i] = costs[i]

# fill up the rest of the table using bottom-up DP
for i in range(n):
    for j in range(2):
        # try cutting the current piece using rod j
        if cut_pieces[i] <= rods[j]:
            dp[i][j] = min(dp[i][j], costs[j])
        # try cutting the current piece using the remaining lengths from previous cuts
        for k in range(i):
            if cut_pieces[i] <= cut_pieces[k]:
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k-1][j])
        # try cutting the current piece using both rods
        for k in range(2):
            if cut_pieces[i] <= rods[k]:
                dp[i][j] = min(dp[i][j], dp[i][k] + costs[j])

# the final answer is in dp[n-1][0]
print(dp[n-1][0])
