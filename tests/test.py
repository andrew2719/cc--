def distance(coordinates, output, start, end):
    if start == end:
        return
    elif start == end-1:
        if abs(coordinates[start][0] - coordinates[end][0]) == 1 and abs(coordinates[start][1] - coordinates[end][1]) == 0:
            output.append((start,end))
        elif abs(coordinates[start][0] - coordinates[end][0]) == 0 and abs(coordinates[start][1] - coordinates[end][1]) == 1:
            output.append((start,end))
        return
    else:
        mid = (start+end)//2
        distance(coordinates, output, start, mid)
        distance(coordinates, output, mid+1, end)
        i = start
        j = mid+1
        while i <= mid and j <= end:
            if coordinates[i][0] < coordinates[j][0]:
                i += 1
            elif coordinates[i][0] > coordinates[j][0]:
                j += 1
            else:
                if abs(coordinates[i][1] - coordinates[j][1]) == 1:
                    output.append((i,j))
                i += 1
                j += 1


if __name__ == "_main_":
    # n = int(input())

    coordinates = [(0, 0), 
                   (1, 0), 
                   (1, 1),
                   (1, 2)]

    # for i in range(n):
    #     x, y = map(int, input().split())
    #     coordinates.append((x, y))

    coordinates.sort()

    output = []

    distance(coordinates, output, 0, len(coordinates)-1)

    for i in range(len(output)):
        print(output[i][0], output[i][1])
