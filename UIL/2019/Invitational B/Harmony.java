import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;

public class Harmony {
    static Scanner in, input, sc;
    public static void main(String[] args) throws IOException {
        in = input = sc = new Scanner(new File("harmony.dat"));
        int n = input.nextInt();
        while(n-->0)
        {
            String s = input.next();
            int oddSum = 0;
            int evenSum = 0;
            int greaterOdd = 0;
            for(int c = 1; c < s.length(); c++)
            {
                if(c%2==0)
                    evenSum += s.charAt(c - 1) - '0';
                else
                {
                    oddSum += Integer.parseInt(s.substring(c-1,c));
                    if(Integer.parseInt(s.substring(c-1,c))>4) greaterOdd++;
                }
            }
            // out.println(evenSum + " " + oddSum + " " + greaterOdd);
            int checkSum = oddSum*3 + evenSum + greaterOdd;
            String checkS = Integer.toString(checkSum);
            // out.println(checkS);
            int lastDigit = Integer.parseInt(s.substring(s.length() - 1));
            int checkDigit = 10-Integer.parseInt(checkS.substring(checkS.length()-1));
            if (checkDigit == 10) checkDigit = 0;
            System.out.print(s);
            if(checkDigit == lastDigit)
                System.out.println(" VALID");
            else
                System.out.println(" INVALID " + checkDigit);
        }

    }
}
