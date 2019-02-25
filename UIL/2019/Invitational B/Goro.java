import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;

public class Goro {
    static Scanner in, input, sc;
    public static void main(String[] args) throws IOException {
        in = input = sc = new Scanner(new File("goro.dat"));

        int N = in.nextInt();
        double res = 0;
        for (int i = 1; i <= N; i++) {
            if (i % 2 != 0)
                res += sqrt(12) / (i * 2 - 1) / Math.pow(3, i - 1);
            else
                res -= sqrt(12) / (i * 2 - 1) / Math.pow(3, i - 1);
            out.printf("%.5f\n", res);
        }

    }
}
