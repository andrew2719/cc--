import random as rd
import time 
import sys
import statistics as st


def quick_sort(arr,pivot):
    if len(arr) <= 1:
        return arr
    # pivot = arr[0]
    left = [x for x in arr[1:] if x <= pivot]
    right = [x for x in arr[1:] if x > pivot]
    return quick_sort(left,pivot) + [pivot] + quick_sort(right,pivot)

def piviot_calc(x,arr):
    if x==0:
        return arr[0]
    elif x==1:
        # return random from arry index
        rdint = rd.randint(0,len(arr)-1)
        return arr[rdint]
    elif x==2:
        r,s,t = 0,len(arr)//2,len(arr)-1
        return st.median([arr[r],arr[s],arr[t]])
    elif x==3:
        r,s,t = len(arr)//4,len(arr)//2,3*len(arr)//4
        return st.median([arr[r],arr[s],arr[t]])
        



def main():

    # Generate a list of 1000 random numbers
    arr = [rd.randint(0, 50) for i in range(10)]
    print(arr)
    '''
    # Sort the list
    start = time.time()
    arr = quick_sort(arr,piviot)
    end = time.time()

    # Print the time it took to sort the list
    print(end - start)
    print(arr)
    '''
    case = int(input("Enter the case number: "))
    # case 1: first element as pivot
    start = time.time()
    arr = quick_sort(arr,piviot_calc(case,arr))
    end = time.time()
    # print upto 10 decimal places
    print("{:.10f}".format(end - start))
    print(arr)

    

if __name__ == "__main__":

    main()