// https://www.codechef.com/viewsolution/19898613
// problem: Chef and Polygon cakes
// status: all test cases passed

import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int noOfTestCases = scan.nextInt();
		while(noOfTestCases > 0)
		{
			int n = scan.nextInt();
			int a = scan.nextInt();
			int k  = scan.nextInt();
			long x = a*n*(n-1) + 360*(n-2)*(k-1) - 2 * a*n*(k-1);
			long y = n*(n-1);
			System.out.println(x/gcd(x,y) +" "+ y/gcd(x,y));
			noOfTestCases--; 
		}
	}

	public static long gcd(long x , long y){
		if(y==0 || x==y)
			return x; 
		else 
		        return gcd(y,x%y);
	}
}