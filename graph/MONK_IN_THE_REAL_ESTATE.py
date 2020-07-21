# https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/monk-in-the-real-estate/
# status: solved

if __name__ == "__main__":
    T = int(input())
    vertices = set()
    while T:
        E = int(input())
        vertices = {int(x) for _ in range(E) for x in input().split()}
        print(len(vertices))
        T -= 1