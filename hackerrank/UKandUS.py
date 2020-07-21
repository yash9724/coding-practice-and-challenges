# UK and US: Part 2
# https://www.hackerrank.com/challenges/uk-and-us-2/problem?h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
import re

N = int(input())
W = []
for i in range(N):
    W.append(input())

T = int(input())

while(T):
    word = input()
    idx = word.index('our')
    obj = re.compile('^'+word[:idx+1]+'u?'+word[idx+2:]+'$')
    count = 0
    for i in range(len(W)):
        for w in W[i].split():
            m = obj.match(w)
            if m:
                count += 1
    print(count)
    T = T-1
