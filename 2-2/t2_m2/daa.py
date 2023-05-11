
rods = [15,14] 
costs = [2, 3] 
cut_pieces = [5,15,10]
cut_pieces = cut_pieces[::-1]
n = len(cut_pieces)
dp = [[float('inf') for i in range(1000)] for j in range(1000)]

def recursive(rods, costs, cut_pieces, i, remaining):
    if i==len(cut_pieces):
        return 0
    min_cost = 1000000000

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

# same question using dp memoization process iterative
def min_cost_bottom_up(rods, costs, cut_pieces):
    n = len(cut_pieces)
    dp = [[float('inf') for i in range(1000)] for j in range(1000)]
    for i in range(n, -1, -1):
        for remaining in range(1000):
            if i == n:
                dp[i][remaining] = 0
                continue
            
            min_cost = float('inf')
            
            if rods[0] >= cut_pieces[i]:
                cost_with_rod1 = costs[0] + dp[i+1][rods[0]-cut_pieces[i]+remaining]
                min_cost = min(min_cost, cost_with_rod1)
            
            if rods[1] >= cut_pieces[i]:
                cost_with_rod2 = costs[1] + dp[i+1][rods[1]-cut_pieces[i]+remaining]
                min_cost = min(min_cost, cost_with_rod2)
            
            if remaining >= cut_pieces[i]:
                cost_with_remaining = dp[i+1][remaining-cut_pieces[i]]
                min_cost = min(min_cost, cost_with_remaining)
            
            dp[i][remaining] = min_cost
    
    return dp[0][0]


print(recursive(rods, costs, cut_pieces, 0, 0))

print(min_cost_top_down(rods, costs, cut_pieces))

# print (dp)
# print("dp")
# for i in range(100):
#     for j in range(15):
#         print(dp[i][j], end='\t')
#     print()


print(min_cost_bottom_up(rods, costs, cut_pieces))








