def convert_base(num, to_base = 10, from_base = 10):
    # first convert to decimal number
    if isinstance(num, str):
        n = int(num, from_base)
    else:
        n = int(num)
    # now convert decimal to 'to_base' base
#    alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    alphabet = "0123456789abcdefghijklmnopqrstuvwxyz"
    if n < to_base:
        return alphabet[n]
    else:
        return convert_base(n // to_base, to_base) + alphabet[n % to_base]

fi = open('input.txt', 'r')
il = fi.readlines()
fi.close()

s = il[0].split('\n')
ss = s[0].split(' ')
n = int(ss[0])
m = int(ss[1])
with open('output.txt', 'w') as f:
    f.write(convert_base(il[1], from_base = n, to_base = m))


