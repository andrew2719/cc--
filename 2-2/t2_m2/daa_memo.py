rods = [12, 15]
costs = [2, 3]
cut_pieces = [3, 5, 9, 10]
cut_pieces.sort(reverse=True)
n = len(cut_pieces)

# findind the min cost to make that cut pieces
# we are maintaing 2 list of r1_remains and r2_remains
# these list will contain the remaining length of the tyope of rod after cutting the pieces
# we traverse all the possible combinations and print  min cost and the total no of types of rods that are used


r1_remains = []
r2_remains = []
def min_cost_fun(r1_remains,r2_remains,i):
    if i == n:
        return 0
    print(r1_remains,r2_remains,i)
    min_cost = float('inf')
    if len(r1_remains):
        for x in range(len(r1_remains)):
            if r1_remains[x]>=cut_pieces[i]:
                r1_remains[x] = r1_remains[x]-cut_pieces[i]
                min_cost = min(min_cost,costs[0]+min_cost_fun(r1_remains,r2_remains,i+1))
                r1_remains[x] = r1_remains[x]+cut_pieces[i]



    if len(r2_remains):
        for x in range(len(r2_remains)):
            if r2_remains[x]>=cut_pieces[i]:
                r2_remains[x] = r2_remains[x]-cut_pieces[i]
                min_cost = min(min_cost,costs[1]+min_cost_fun(r1_remains,r2_remains,i+1))
                r2_remains[x] = r2_remains[x]+cut_pieces[i]
            

    if rods[0]>=cut_pieces[i]:
        r1_remains.append(rods[0]-cut_pieces[i])
        min_cost = min(min_cost,costs[0]+min_cost_fun(r1_remains,r2_remains,i+1))
        r1_remains.pop()

    if rods[1]>=cut_pieces[i]:
        r2_remains.append(rods[1]-cut_pieces[i])
        min_cost = min(min_cost,costs[1]+min_cost_fun(r1_remains,r2_remains,i+1))
        r2_remains.pop()

    return min_cost

print(min_cost_fun(r1_remains,r2_remains,0))

    


    


    
