rods = [12, 15]
costs = [2, 3]
cut_pieces = [6,6,6,6,6,6,6,6]
cut_pieces.sort(reverse=True)
n = len(cut_pieces)

# findind the min cost to make that cut pieces
# we are maintaing 2 list of r1_remains and r2_remains
# these list will contain the remaining length of the tyope of rod after cutting the pieces
# we traverse all the possible combinations and print  min cost and the total no of types of rods that are used

min_cost = float('inf')

def min_cost_fun(r1_remains,r2_remains,i):
    if i == n:
        return 0
    
    global min_cost
    if len(r1_remains):
        for x in range(len(r1_remains)):
            if r1_remains[x]>=cut_pieces[i]:
                remaining = r1_remains[x]-cut_pieces[i]
                new_r1_remains = []
                new_r1_remains.append(remaining)
                min_cost = min(min_cost,min_cost_fun(new_r1_remains,r2_remains,i+1))
                

    if len(r2_remains):
        for x in range(len(r2_remains)):
            if r2_remains[x]>=cut_pieces[i]:
                remaining = r2_remains[x]-cut_pieces[i]
                new_r2_remains = []
                new_r2_remains.append(remaining)
                min_cost = min(min_cost,min_cost_fun(r1_remains,new_r2_remains,i+1))
                #print("min_cost",min_cost)
            

    if rods[0]>=cut_pieces[i]:
        r1_remains.append(rods[0]-cut_pieces[i])
        min_cost = min(min_cost,costs[0]+min_cost_fun(r1_remains,r2_remains,i+1))
        r1_remains.pop() # this pop is done because we cannot go ahead with this combination
        #print("min_cost",min_cost)

    if rods[1]>=cut_pieces[i]:
        r2_remains.append(rods[1]-cut_pieces[i])
        min_cost = min(min_cost,costs[1]+min_cost_fun(r1_remains,r2_remains,i+1))
        r2_remains.pop()
        #print("min_cost",min_cost)


    return min_cost


# memoization solution
def min_cost_fun_memo(r1_remains,r2_remains,i,memo):
    if i == n:
        return 0
    
    global min_cost
    # memoization
    if (tuple(r1_remains),tuple(r2_remains),i) in memo:
        return memo[(tuple(r1_remains),tuple(r2_remains),i)]
    
    if len(r1_remains):
        for x in range(len(r1_remains)):
            if r1_remains[x]>=cut_pieces[i]:
                remaining = r1_remains[x]-cut_pieces[i]
                new_r1_remains = []
                new_r1_remains.append(remaining)
                min_cost = min(min_cost,min_cost_fun_memo(new_r1_remains,r2_remains,i+1,memo))

    if len(r2_remains):
        for x in range(len(r2_remains)):
            if r2_remains[x]>=cut_pieces[i]:
                remaining = r2_remains[x]-cut_pieces[i]
                new_r2_remains = []
                new_r2_remains.append(remaining)
                min_cost = min(min_cost,min_cost_fun_memo(r1_remains,new_r2_remains,i+1,memo))
                #print("min_cost",min_cost)

    if rods[0]>=cut_pieces[i]:
        r1_remains.append(rods[0]-cut_pieces[i])
        min_cost = min(min_cost,costs[0]+min_cost_fun_memo(r1_remains,r2_remains,i+1,memo))
        r1_remains.pop()
        #print("min_cost",min_cost)

    if rods[1]>=cut_pieces[i]:
        r2_remains.append(rods[1]-cut_pieces[i])
        min_cost = min(min_cost,costs[1]+min_cost_fun_memo(r1_remains,r2_remains,i+1,memo))
        r2_remains.pop()
        #print("min_cost",min_cost)

    memo[(tuple(r1_remains),tuple(r2_remains),i)] = min_cost

    return min_cost
    

# using dynamic programing the above problem can be solved in O(n^2) time complexity
# we will use a 2d array to store the min cost for each cut piece

def min_cost_fun_dp():
    
    dp = [[float('inf') for _ in range(n+1)] for _ in range(n+1)]
    dp[0][0] = 0

    for i in range(1,n+1):
        for j in range(1,n+1):
            if cut_pieces[i-1]<=rods[0]:
                dp[i][j] = min(dp[i][j],dp[i-1][j-1]+costs[0])
            if cut_pieces[i-1]<=rods[1]:
                dp[i][j] = min(dp[i][j],dp[i-1][j-1]+costs[1])
            if cut_pieces[i-1]<=rods[0]:
                dp[i][j] = min(dp[i][j],dp[i][j-1]+costs[0])
            if cut_pieces[i-1]<=rods[1]:
                dp[i][j] = min(dp[i][j],dp[i][j-1]+costs[1])
    
    return dp[n][n]

print(min_cost_fun([],[],0))
print(min_cost_fun_memo([],[],0,{}))
print(min_cost_fun_dp())




    


    


    
