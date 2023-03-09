import random
import time
import statistics

# quick sort function

def quick_sort(arr, pivot_type):
    if len(arr) <= 1:
        return arr
    if pivot_type == 0:
        pivot = arr[0]
    elif pivot_type == 1:
        pivot = arr[random.randint(0, len(arr) - 1)]
    elif pivot_type == 2:
        r = arr[0]
        s = arr[len(arr) // 2]
        t = arr[len(arr) - 1]
        pivot = statistics.median([r, s, t])
    elif pivot_type == 3:
        
        r = arr[len(arr) // 4]
        s = arr[len(arr) // 2]
        t = arr[3 * len(arr) // 4]
        pivot = statistics.median([r, s, t])
    less = []
    equal = []
    greater = []
    for x in arr:
        if x < pivot:
            less.append(x)
        elif x == pivot:
            equal.append(x)
        else:
            greater.append(x)
    return quick_sort(less, pivot_type) + equal + quick_sort(greater, pivot_type)


if __name__ == '__main__':
    
    
    arr = [random.randint(0, 10000000) for i in range(10000000)]
    # create 4 copies of the array
    arr1 = arr.copy()
    arr2 = arr.copy()
    arr3 = arr.copy()
    arr4 = arr.copy()
    # print("Original array: ", arr)

    
    start_time = time.time()
    arr = quick_sort(arr1, 0)
    # print("Sorted array: ", arr)
    print("Time taken: ", round(time.time() - start_time, 20))

    start_time = time.time()
    arr = quick_sort(arr2, 1)
    # print("Sorted array: ", arr)
    print("Time taken: ", round(time.time() - start_time, 20))

    start_time = time.time()
    arr = quick_sort(arr3, 2)
    # print("Sorted array: ", arr)
    print("Time taken: ", round(time.time() - start_time, 20))

    start_time = time.time()
    arr = quick_sort(arr4, 3)
    # print("Sorted array: ", arr)
    print("Time taken: ", round(time.time() - start_time, 20))

    
    





    