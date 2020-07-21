# Enormous Input Test | Problem Code : INTEST
# https://www.codechef.com/viewsolution/19971950
# status: All test cases passed

def main():
	n,k = [int(x) for x in input().split()]
	total = 0
	for _ in range(n):
		t = int(input())
		if t % k == 0:
			total+=1
	print(total)		

if __name__ == '__main__':
	main()
