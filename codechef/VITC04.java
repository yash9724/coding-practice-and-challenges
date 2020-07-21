// Problem: VITC04 Contest: Practice(extcontest) 
// https://www.codechef.com/viewsolution/19986060
// status: all test cases passed

import java.util.Scanner;
import java.util.Arrays;

public class Main
    {

        public static void main(String[] args)
        {
            Scanner input = new Scanner(System.in);

            int testCases = input.nextInt();

            for( int i = 0 ; i < testCases ; i++)
            {
                int N = input.nextInt();
                int[] menHotness = new int[N];
                for( int count = 0 ; count < N  ; count++ )
                {
                    menHotness[count] = input.nextInt();
                }

                Arrays.sort(menHotness);




                int[] womenHotness = new int[N];
                for( int count = 0 ; count < N  ; count++ )
                {
                    womenHotness[count] = input.nextInt();
                }

                Arrays.sort(womenHotness);
                int hotnessBond = 0;

                for( int count = 0 ; count < N ; count++)
                {
                    hotnessBond  = hotnessBond +  ( menHotness[count] * womenHotness[count] );
                }
                System.out.println(hotnessBond);


            }


        }


}
