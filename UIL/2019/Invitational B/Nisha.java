import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;

public class Nisha {
    static Scanner in, input, sc;
    public static void main(String[] args) throws IOException {
        in = input = sc = new Scanner(new File("nisha.dat"));

        int TC = in.nextInt();
        for (int tc = 1; tc <= TC; tc++) {
            long K = in.nextLong();
            long ans = K;
            for (int i = 0; i < K - 1; i++)
                ans *= 2;
            ans += 1;
            out.printf("Case #%d: %d\n", tc, ans);
        }

    }
}
