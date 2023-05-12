def recursive(rods, costs, cut_pieces, i, remaining, used_rods):
    if i == len(cut_pieces):
        return 0
    
    min_cost = float('inf')
    cost_with_rod1 = cost_with_rod2 = cost_with_remaining = float('inf')
    
    # Try using rod type 1
    if rods[0] >= cut_pieces[i]:
        new_remaining = rods[0] - cut_pieces[i] + remaining
        new_used_rods = used_rods[:]
        new_used_rods[0] += 1
        cost_with_rod1 = costs[0] + recursive(rods, costs, cut_pieces, i+1, new_remaining, new_used_rods)
        min_cost = min(min_cost, cost_with_rod1)

    # Try using rod type 2
    if rods[1] >= cut_pieces[i]:
        new_remaining = rods[1] - cut_pieces[i] + remaining
        new_used_rods = used_rods[:]
        new_used_rods[1] += 1
        cost_with_rod2 = costs[1] + recursive(rods, costs, cut_pieces, i+1, new_remaining, new_used_rods)
        min_cost = min(min_cost, cost_with_rod2)

    # Try using remaining length from the previous rod
    if remaining >= cut_pieces[i]:
        cost_with_remaining = recursive(rods, costs, cut_pieces, i+1, remaining - cut_pieces[i], used_rods)
        min_cost = min(min_cost, cost_with_remaining)

    return min_cost

rods = [12, 15]
costs = [2, 3]
cut_pieces = [10, 9, 5, 3]  # Descending order

used_rods = [0, 0]  # Initialize the count of used rods
min_cost = recursive(rods, costs, cut_pieces, 0, 0, used_rods)

print("Minimum cost:", min_cost)
print("Rod 1 used:", used_rods[0])
print("Rod 2 used:", used_rods[1])
