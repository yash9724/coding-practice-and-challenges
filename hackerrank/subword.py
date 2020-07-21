# Find a subword
# https://www.hackerrank.com/challenges/find-substring/problem?h_r=next-challenge&h_v=zen


import re

N = int(input())
W = []
for i in range(N):
    W.append(input())

T = int(input())

while(T):
    s = input()
    count = 0
    for i in range(len(W)):
        for w in re.split('\W+', W[i]):
            m = re.match(r'\w+'+s+r'\w+', w)
            if m:
                count += 1
    print(count)
    T = T-1
