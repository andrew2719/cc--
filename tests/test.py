
s = '0000000000000000000312090cf291d57515a48f1c26c1c0afc94d290e00a3f8'

#coinverting sha256 to bin
s = bin(int(s, 16))[2:].zfill(256)

print(s)