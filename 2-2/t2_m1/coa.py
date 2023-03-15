import random


def dec_to_sign_mag(num):
    if num >= 0:
        sign = '0'
    else:
        sign = '1'
        num = abs(num)
    bin_num = bin(num)[2:]
    return sign + bin_num.zfill(5)

def dec_to_twos_comp(num):
    if num >= 0:
        sign = '0'
        bin_num = bin(num)[2:].zfill(5)
    else:
        sign = '1'
        num = abs(num)
        bin_num = bin(num)[2:].zfill(5)
        bin_num = bin(int(''.join(['1' if x == '0' else '0' for x in bin_num]), 2) + 1)[2:]
    return sign + bin_num


ls = [int(x) for x in input().split()]
print(ls)
print([dec_to_sign_mag(x) for x in ls])
print([dec_to_twos_comp(x) for x in ls])
