/* D - Triangle Count  |   Problem Code: ZUBTRCNT  */
// https://www.codechef.com/viewsolution/20187219
// status: All test cases passed

import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		int i = 1;
		while(testCases-- > 0){
			int length = scan.nextInt();
			int reqLen = scan.nextInt();
			if(reqLen > length){
				System.out.printf("Case %d: 0\n",i);
				i++;
				continue;
			}
			int n = length - reqLen + 1;
			int validTriangles = (n*(n+1))/2;
			System.out.printf("Case %d: %d\n",i,validTriangles);
			i++;
		}
	}
}