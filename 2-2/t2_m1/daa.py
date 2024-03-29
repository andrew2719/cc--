count = 0
total_time = 0


def two_left_case(a_side, b_side):
    if count+max(a_side)>x:
        return
    
    move_from_a_to_b(a_side[0], a_side[1], a_side, b_side)


def three_left_case(a_side, b_side):
    if count+max(a_side)>=x:
        return
    move_from_a_to_b(max(a_side), min(a_side), a_side, b_side)
    if count+min(b_side)>=x:
        return
    move_from_b_to_a(min(b_side), a_side, b_side)
    print("Move %s back to A side" % str(min(b_side)))


def four_or_more_case(a_side, b_side):
    if count+sorted(a_side)[1]>=x:
        return
    move_from_a_to_b(min(a_side), sorted(a_side)[1], a_side, b_side)

    if count+min(b_side)>=x:
        return
    move_from_b_to_a(min(b_side), a_side, b_side)

    if count+max(a_side)>=x:
        return
    move_from_a_to_b(max(a_side), sorted(a_side)[-2], a_side, b_side)

    if count+min(b_side)>=x:
        return
    move_from_b_to_a(min(b_side), a_side, b_side)


def move_from_a_to_b(first_number, second_number, a_side, b_side):
    global count
    # total_time += second_number
    a_side.remove(first_number)
    a_side.remove(second_number)
    b_side.append(first_number)
    b_side.append(second_number)
    count += max(first_number, second_number)
    print("Move %s & %s to B side." % (str(first_number), str(second_number)))


def move_from_b_to_a(number, a_side, b_side):
    global count
    # total_time += number
    b_side.remove(number)
    a_side.append(number)
    count += number
    print("Move %s back to A side." % str(number))


if __name__ == '__main__':
    while(True):
        a_side = [int(x) for x in input("Enter time of each person: ").split()]
        b_side = []
        x = int(input("Enter the time limit: "))
        while len(a_side) != 0 and count <x:
            if count>=x:
                break
            if len(a_side) == 1:
                if a_side[0]>x:
                    break
                print("Just bring that number to B...")
                b_side.append(a_side[0])
                a_side.clear()
                break
            if len(a_side) == 2:
                two_left_case(a_side, b_side)
                print("Total time count: %s" % str(count))
                count = 0
                
                break
            elif len(a_side) == 3:
                three_left_case(a_side, b_side)
            else:
                four_or_more_case(a_side, b_side)

        print("A side",*a_side)
        print("B side",*b_side)

            


