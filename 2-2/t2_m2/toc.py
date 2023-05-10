# conversion of context free grammar to pushdown automata of {ww^R | w ∈ {a, b}*}
# where w^R is the reverse of w

cfg = {"S": ["aSa", "bSb"]}

s = input("Enter a string: ")

def check(s):
    # if first half and second half are mirror images
    if s[:len(s)//2] == s[len(s)//2:][::-1]:
        return True
    else:
        return False
    
def toc(s):

    # if string is empty
    if(check(s)):
        return True
    
    if s == "":
        return True

    # if string is not empty
    else:
        for i in cfg:
            for j in cfg[i]:
                if s.startswith(j):
                    # print(s, j)
                    if toc(s[len(j):]):
                        return True
        return False
    
if toc(s):
    print("Accepted")
else:
    print("Rejected")

# Input: aabbaa
