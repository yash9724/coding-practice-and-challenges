// to calculate total number of squares in N*N square grid

import java.util.Scanner;


public class Feynman
{
	public static void main( String[] args)
	{
		Scanner input = new Scanner(System.in);

		float squares;
		int N = input.nextInt();
		while( N != 0 )
		{
			
			squares =  totalSquares(N);
			System.out.println(squares);
			N = input.nextInt();
		}
	}

	public static float totalSquares( int N )
	{
		return (N*( N + 1 )*( 2*N  + 1)) / 6;
	}
}