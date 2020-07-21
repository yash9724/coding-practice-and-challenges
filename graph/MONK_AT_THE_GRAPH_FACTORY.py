# https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/monk-at-the-graph-factory/
# status: solved

n = int(input())
degree = [int(x) for x in input().split()]
if sum(degree) == 2*(n-1):
    print('Yes')
else:
    print('No')
