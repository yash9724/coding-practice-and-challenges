# https://www.codechef.com/SEPT18B/status/MAGICHF,yash9724
# problem: MAgician versus Chef 2
# status: all test cases passed

def main():
  from sys import stdin
  testCases = int(input())
  while testCases:
    noOfBoxes,xBox,noOfSwaps = [int(i) for i in input().split()]
    for _ in range(noOfSwaps):
      line = stdin.readline()
      t = tuple(map(int,line.split()))
      if(t.count(xBox) != 0):
        if(t[0] != xBox):
          xBox = t[0]
        else:
          xBox = t[1] 
    print(xBox)       
    testCases -= 1


if __name__ == '__main__':
  main()