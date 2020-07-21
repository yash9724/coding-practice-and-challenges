# Tickets | Problem Code: TICKETS5
# https://www.codechef.com/status/TICKETS5,yash9724
# status: all test cases passed

def main():
	from math import ceil
	testCases = int(input())
	while testCases:
		S = input()
		oddPos = S[1::2]
		evenPos = S[::2]
		length = len(S)
		oddFirstCount = oddPos.count(oddPos[0])
		evenFirstCount = evenPos.count(evenPos[0])
		if(((oddFirstCount == length // 2 and evenFirstCount == ceil(length/2)) or (oddFirstCount == ceil(length/2) and evenFirstCount == length // 2 )) and (oddPos[0] != evenPos[0])):
			print('YES')
		else:
			print('NO')
		testCases = testCases - 1	

if __name__ == '__main__':
	main()
