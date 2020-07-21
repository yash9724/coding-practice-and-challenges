#XOR Again | Problem Code: XORAGN
# https://www.codechef.com/status/XORAGN,yash9724
# status: All test cases passed

def main():
	from sys import stdin
	testCases = int(stdin.readline())
	A = []
	while testCases:
		N = int(stdin.readline())
		A = [int(x) for x in stdin.readline().split()]
		output = 0
		for i in range(N):
			output = output ^ (2*A[i])
		print(output)	 
		testCases = testCases - 1

if __name__ == '__main__':
	main()


