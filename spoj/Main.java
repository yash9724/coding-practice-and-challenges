//  number of trailing zeros

import java.util.Scanner;
import java.lang.Math;
import java.lang.System;


public class Main
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner( System.in);

		int T = input.nextInt();

		for( int i = 1 ; i <= T ; i++ )
			{
				int num = input.nextInt();
				num = trailingZeros(num);
				System.out.println(num);
			}
	}

	public static int trailingZeros( int num )
	{
		int numTrailZeros = 0 , i = 1;

		while(true)
		{
			if( num / Math.pow( 5, i) == 0)
				break;

			numTrailZeros = numTrailZeros +  (int)Math.floor( num / Math.pow( 5 , i++));



		}

		return numTrailZeros;

	}
}