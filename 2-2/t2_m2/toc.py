# accepted strings are "aSa" and "bSb"
# where S can be replaced with "aSb" or "bSa" or epsilon
# S -> aSb | bSa | epsilon
st = ""
flag = 0
def check_cfg(st,s):
    # base case 
    if(len(st)>len(s)):
        return 

    if(st==s):
        print("Accepted")
        global flag
        flag = 1
        return
    
    first = st[:len(st)//2]
    second = st[len(st)//2:]
    check_cfg(first+"aa"+second, s)
    check_cfg(first+"bb"+second, s)
    #print(st)


s = input("Enter string: ")
check_cfg(st,s)
if(flag==0):
    print("Not Accepted")



