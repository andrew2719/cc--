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

# r1_remains = []
# r2_remains = []
def min_cost_fun(r1_remains,r2_remains,i):
    if i == n:
        return 0
    print(r1_remains,r2_remains,i)
    global min_cost
    if len(r1_remains):
        for x in range(len(r1_remains)):
            if r1_remains[x]>=cut_pieces[i]:
                remaining = r1_remains[x]-cut_pieces[i]
                new_r1_remains = []
                new_r1_remains.append(remaining)
                print("new_remains",new_r1_remains)
                min_cost = min(min_cost,min_cost_fun(new_r1_remains,r2_remains,i+1))
                print("min_cost",min_cost)



    if len(r2_remains):
        for x in range(len(r2_remains)):
            if r2_remains[x]>=cut_pieces[i]:
                remaining = r2_remains[x]-cut_pieces[i]
                new_r2_remains = []
                new_r2_remains.append(remaining)
                min_cost = min(min_cost,min_cost_fun(r1_remains,new_r2_remains,i+1))
                print("min_cost",min_cost)
            

    if rods[0]>=cut_pieces[i]:
        r1_remains.append(rods[0]-cut_pieces[i])
        min_cost = min(min_cost,costs[0]+min_cost_fun(r1_remains,r2_remains,i+1))
        r1_remains.pop()
        print("min_cost",min_cost)

    if rods[1]>=cut_pieces[i]:
        r2_remains.append(rods[1]-cut_pieces[i])
        min_cost = min(min_cost,costs[1]+min_cost_fun(r1_remains,r2_remains,i+1))
        r2_remains.pop()
        print("min_cost",min_cost)



    return min_cost

    

print(min_cost_fun([],[],0))

    


    


    
