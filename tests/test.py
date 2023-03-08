n,k = [int(x) for x in input().split()]

a = [int(x) for x in input().split()]

maxi = -1

# if k is > n, then we can't have a subarray of size k
if k > n:
    print(-1)
    exit()

for i in range(n-k+1):
    maxi = max(maxi, sum(a[i:i+k]))