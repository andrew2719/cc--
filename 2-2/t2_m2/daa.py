
rods = [12,15] 
costs = [2, 3] 
cut_pieces = [3,5,9,10]
cut_pieces.sort()
cut_pieces  = cut_pieces[::-1]
n = len(cut_pieces)
dp = [[float('inf') for i in range(1000)] for j in range(1000)]
rod_1 = rod_2 = 0
def recursive(rods, costs, cut_pieces, i, remaining):
    if i==len(cut_pieces):
        return 0
    min_cost = 1000000000
    cost_with_rod1 = cost_with_rod2 = cost_with_remaining = float('inf')
    # Try using rod type 1
    if rods[0] >= cut_pieces[i]:
        cost_with_rod1 = costs[0] + recursive(rods, costs, cut_pieces, i+1, rods[0]-cut_pieces[i]+remaining)
        min_cost = min(min_cost, cost_with_rod1)

    # Try using rod type 2
    if rods[1] >= cut_pieces[i]:
        cost_with_rod2 = costs[1] + recursive(rods, costs, cut_pieces, i+1, rods[1]-cut_pieces[i]+remaining)
        min_cost = min(min_cost, cost_with_rod2)

    # Try using remaining length from previous rod
    if remaining >= cut_pieces[i]:
        cost_with_remaining = recursive(rods, costs, cut_pieces, i+1, remaining-cut_pieces[i])
        min_cost = min(min_cost, cost_with_remaining)


    return min_cost



def min_cost_top_down(rods, costs, cut_pieces):
    n = len(cut_pieces)
    
    def recursive_min_cost(i, remaining):
        if i == n:
            return 0
        
        if dp[i][remaining] != float('inf'):
            return dp[i][remaining]
        
        min_cost = float('inf')
        
        if rods[0] >= cut_pieces[i]:
            cost_with_rod1 = costs[0] + recursive_min_cost(i+1, rods[0]-cut_pieces[i]+remaining)
            min_cost = min(min_cost, cost_with_rod1)
        
        if rods[1] >= cut_pieces[i]:
            cost_with_rod2 = costs[1] + recursive_min_cost(i+1, rods[1]-cut_pieces[i]+remaining)
            min_cost = min(min_cost, cost_with_rod2)
        
        if remaining >= cut_pieces[i]:
            cost_with_remaining = recursive_min_cost(i+1, remaining-cut_pieces[i])
            min_cost = min(min_cost, cost_with_remaining)
        
        dp[i][remaining] = min_cost
        return min_cost
    
    return recursive_min_cost(0, 0)

def getMinCost(rods, costs, cut_pieces):
    n = len(cut_pieces)
    r1, r2 = rods[0], rods[1]

    # Create a 3D DP table to store the minimum cost
    dp = [[[float('inf')] * (r2 + 1) for _ in range(r1 + 1)] for _ in range(n + 1)]

    # Base case: when no cut pieces are left, cost is 0
    for i in range(r1 + 1):
        for j in range(r2 + 1):
            dp[n][i][j] = 0

    # Iterate from the last cut piece to the first
    for i in range(n - 1, -1, -1):
        for remaining1 in range(r1 + 1):
            for remaining2 in range(r2 + 1):
                # Try using rod type 1
                if remaining1 >= cut_pieces[i]:
                    dp[i][remaining1][remaining2] = min(
                        dp[i][remaining1][remaining2],
                        costs[0] + dp[i + 1][remaining1 - cut_pieces[i]][remaining2]
                    )

                # Try using rod type 2
                if remaining2 >= cut_pieces[i]:
                    dp[i][remaining1][remaining2] = min(
                        dp[i][remaining1][remaining2],
                        costs[1] + dp[i + 1][remaining1][remaining2 - cut_pieces[i]]
                    )

                # Try using remaining length from the previous rod
                dp[i][remaining1][remaining2] = min(
                    dp[i][remaining1][remaining2],
                    dp[i + 1][remaining1][remaining2]
                )

    return dp[0][r1][r2]

print(recursive(rods, costs, cut_pieces, 0, 0))
print(rod_1)
print(rod_2)

print(min_cost_top_down(rods, costs, cut_pieces))

# print (dp)
# print("dp")
# for i in range(100):
#     for j in range(15):
#         print(dp[i][j], end='\t')
#     print()

print(getMinCost(rods, costs, cut_pieces))














