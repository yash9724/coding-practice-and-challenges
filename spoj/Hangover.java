//SPOJ                 HANGOVER - Hangover                #math

import java.lang.Math;
import java.util.Scanner;
import java.util.NoSuchElementException;



public class Hangover
{
	public static void main(String[] args)  throws java.lang.Exception
	{
		
 		Scanner scanner = new Scanner(System.in);
 		float value;
		try
		{ 
		    value = scanner.nextFloat();
 			//value = (float)(Math.floor(value * 100.00) / 100.00 );
		

 		while( value != 0.00)
        {
 			
 			//System.out.println(value);
 			float sum =0.0f;
 			int i = 2;

 			while(value > sum)
 			{
 				sum = (float)(sum + 1.00/i);
 				i++;
 			}

 		System.out.println(i-2 + " card(s)");

 		value = scanner.nextFloat();
 		//value = (float)(Math.floor(value * 100.00) / 100.00 );
	     

		}
	}
	catch(NoSuchElementException e)
	{
		//System.out.println(e.getMessage());
	}

	}	
}