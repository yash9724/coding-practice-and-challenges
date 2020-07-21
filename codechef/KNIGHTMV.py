#Correctness of Knight Move   |   Problem Code: KNIGHTMV
# https://www.codechef.com/viewsolution/20143662
# status: All test cases passed 

def main():
  from re import fullmatch 
  testCases = int(input())
  while testCases:
    string = input()
    match = fullmatch(r'[a-h][1-8]-[a-h][1-8]',string)
    if match != None:
      a1 = ord(string[0])-96
      b1 = ord(string[1])-96
      a2 = ord(string[3])-96
      b2 = ord(string[4])-96
      if abs((a1-a2)*(b1-b2)) == 2:
        print('Yes')
      else:
        print('No')  
    else:
        print('Error') 
    testCases -= 1


if __name__ == '__main__':
  main()

