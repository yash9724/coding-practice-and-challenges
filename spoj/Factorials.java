// calculating factorials using BigInteger class

import java.math.BigInteger;


public class Factorials
{
	public static BigInteger factorial( BigInteger number )
	{
		if(number.compareTo(BigInteger.ONE) <= 0)
			return BigInteger.ONE;

		return number.multiply(factorial(number.subtract(BigInteger.ONE)));
	}

	public static void main(String[] args)
	{
		BigInteger fact;
		for(int i = 0 ; i <= 100 ; i++)
		{
			fact = factorial(BigInteger.valueOf(i));
			System.out.println(fact);
		}
	}
}