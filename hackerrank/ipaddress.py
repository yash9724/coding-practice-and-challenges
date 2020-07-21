import re

n = int(input())
for i in range(n):
    w = input()
    if re.match(r'^\d\d?\d?\.\d\d?\d?\.\d\d?\d?\.\d\d?\d?$', w):
        print('IPv4')
    elif re.match(r'^[0-9a-f]{1,4}:[0-9a-f]{1,4}:[0-9a-f]{1,4}:[0-9a-f]{1,4}:[0-9a-f]{1,4}:[0-9a-f]{1,4}:[0-9a-f]{1,4}:[0-9a-f]{1,4}$', w):
        print('IPv6')
    else:
        print('Neither')