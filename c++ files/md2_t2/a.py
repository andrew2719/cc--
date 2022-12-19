class Node:
    def __init__(self, value):
        self.value = value
        self.left = self.right = None
    

def insert(n):
    mid = len(n) // 2
    root = Node(n[mid])
    if len(n) > 1:
        root.left = insert(n[:mid])
        root.right = insert(n[mid+1:])
    return root

def print_tree(root):
    if root:
        print(root.value)
        print_tree(root.left)
        print_tree(root.right)

def insert2(i,j,n):
    mid = (i+j) // 2
    root = Node(n[mid])
    if i < j:
        print("left = ",n[i:mid])
        root.left = insert2(i,mid-1,n)
        print("right = ",n[mid+1:j+1])
        root.right = insert2(mid+1,j,n)
    return root

n = [1, 2, 3, 4, 5, 6, 7,8,9]
root = insert(n)
# root = insert2(0,len(n)-1,n)
print_tree(root)



