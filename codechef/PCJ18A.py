#Chef and Secret Ingredient----------------------------------------- Problem Code: PCJ18A
# https://www.codechef.com/status/PCJ18A,yash9724
# status: All test cases passed

testCases = int(input())
while testCases > 0:
	N,X = [int(x) for x in input().split()]
	l = [int(x) for x in input().split()]
	count = 0
	for A in l:
		if A >= X:
			count = count + 1
			break
	if count > 0:
		print("YES")
	else:
		print("NO")	
	testCases = testCases -1
	