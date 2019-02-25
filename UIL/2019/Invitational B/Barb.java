import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;

public class Barb {
    static Scanner in, input, sc;
    public static void main(String[] args) throws IOException {
        in = input = sc = new Scanner(new File("barb.dat"));

        int N = in.nextInt();
        out.printf("A   A*A   3*A   A/2\n");
        for (int i = 1; i <= N; i++) {
            out.printf("%d     %d     %d     %d\n", i, i * i, 3 * i, i / 2);
        }

    }
}
