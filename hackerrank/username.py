import re

n = int(input())
for i in range(n):
    w = input()
    if re.match(r'^[._][0-9]+[a-zA-Z]*_?$', w):
        print('VALID')
    else:
        print('INVALID')