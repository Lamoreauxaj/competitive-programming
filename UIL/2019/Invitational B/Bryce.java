import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;

public class Bryce {
    static Scanner in, input, sc;
    public static void main(String[] args) throws IOException {
        in = input = sc = new Scanner(new File("bryce.dat"));

        while (in.hasNext()) {
            int N = in.nextInt();
            String roman = "";
            int V = N;
            while (N > 0) {
                if (N >= 1000) { roman += "M"; N -= 1000; }
                else if (N >= 900) { roman += "CM"; N -= 900; }
                else if (N >= 500) { roman += "D"; N -= 500; }
                // else if (N >= 400) { roman += "CD"; N -= 400; }
                else if (N >= 100) { roman += "C"; N -= 100; }
                else if (N >= 90) { roman += "XC"; N -= 90; }
                else if (N >= 50) { roman += "L"; N -= 50; }
                // else if (N >= 40) { roman += "XL"; N -= 40; }
                else if (N >= 10) { roman += "X"; N -= 10; }
                else if (N >= 9) { roman += "IX"; N -= 9; }
                else if (N >= 5) { roman += "V"; N -= 5; }
                else if (N >= 4) { roman += "IV"; N -= 4; }
                else if (N >= 1) { roman += "I"; N -= 1; }
            }
            out.printf("%d:%s\n", V, roman);
        }

    }
}
