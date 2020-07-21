// This program counts number of different squares that can be formed from 'n' squares of size 1 unit
//SPOJ    AE00 - Rectangles     #ad-hoc


import java.util.Scanner;
import  java.util.NoSuchElementException;	

public class Rectangles
{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		//System.out.println("Enter number of unit sized squares:");
		
		try
		{
		int n = scanner.nextInt();
		 System.out.println(noOfRectangles(n));
	}
	catch(NoSuchElementException e)
	{
		System.out.println(e.getMessage());
		System.exit(0);
	}

		
	}


	public static int noOfRectangles( int n)
	{
		int i , j , count = 0;

		for(  i = 1; i <= n ; i++ )
			for( j = i * i ; j <= n ;  j =j + i)
				count++;


		return count;
	}
}