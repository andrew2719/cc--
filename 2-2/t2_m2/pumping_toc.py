#pumping lema for cfl
# L = {0^i1^i2^i | i>=0}
s = "aabbcc"
# uvwxy should have unique characters order to pump like u = "00" or u = "0", v = 

u = s[0]
y = s[-1]
for i in range(1, len(s)):
    if s[i]!=u:
        v = s[1:i]
        break
#check until another different character is found from v ending
stack = [s[len(u)+len(v)]]
w =x= ""
for i in range(len(u+v), len(s)):
    if s[i]==stack[-1]:
        w+=s[i]
        stack.append(s[i])
    else:
        x = s[i:len(s)-len(y)]
        break
# checking for uv^2wx^2y
print(u, v, w,x, y)
print(s, u+v*2+w+x*2+y)
print((len(u+v*2+w+x*2+y)==len(s)))
