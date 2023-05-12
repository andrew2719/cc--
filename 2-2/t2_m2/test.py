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
    

# iterative dp solution
def min_cost_fun_dp(r1_remains,r2_remains,i,dp,n):
    # finding the solution using iterative dp
    # using bottom up approach

    # dp[i][j] will store the min cost for the remaining rods
    # i is the index of the cut_pieces
    # j is the index of the rods
    # dp[i][j] will store the min cost for the remaining rods

    for i in range(n,-1,-1):
        for j in range(n,-1,-1):
            if i == n:
                dp[i][j] = 0
            else:
                min_cost = float('inf')
                if len(r1_remains):
                    for x in range(len(r1_remains)):
                        if r1_remains[x]>=cut_pieces[i]:
                            remaining = r1_remains[x]-cut_pieces[i]
                            new_r1_remains = []
                            new_r1_remains.append(remaining)
                            min_cost = min(min_cost,dp[i+1][j])
                            

                if len(r2_remains):
                    for x in range(len(r2_remains)):
                        if r2_remains[x]>=cut_pieces[i]:
                            remaining = r2_remains[x]-cut_pieces[i]
                            new_r2_remains = []
                            new_r2_remains.append(remaining)
                            min_cost = min(min_cost,dp[i+1][j])
                            

                if rods[0]>=cut_pieces[i]:
                    r1_remains.append(rods[0]-cut_pieces[i])
                    min_cost = min(min_cost,costs[0]+dp[i+1][j])
                    r1_remains.pop()

                if rods[1]>=cut_pieces[i]:
                    r2_remains.append(rods[1]-cut_pieces[i])
                    min_cost = min(min_cost,costs[1]+dp[i+1][j])
                    r2_remains.pop()

                dp[i][j] = min_cost

    for i in dp:
        print(i)
    return dp[0][0]


print(min_cost_fun([],[],0))

# memoization solution
memo = {}
print(min_cost_fun_memo([],[],0,memo))

# print the memo
for i in memo:
    print(i,memo[i])

# dp solution
dp = [[0 for i in range(n+1)] for j in range(n+1)]

print(min_cost_fun_dp([],[],0,dp,n))


    


    
