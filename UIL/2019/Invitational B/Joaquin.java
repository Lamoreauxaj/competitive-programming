import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;

public class Joaquin {
    static Scanner in, input, sc;
    public static void main(String[] args) throws IOException {
        in = input = sc = new Scanner(new File("joaquin.dat"));

        int TC = in.nextInt();
        while (TC-- > 0) {
            int N = in.nextInt();

            char[][] grid = new char[N][N];
            for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
                grid[i][j] = ' ';
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    int d = Math.min(i + 1, N - i);
                    d = Math.min(d, Math.min(j + 1, N - j));
                    if (d % 2 != 0)
                        grid[i][j] = 'X';
                }
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++)
                    out.printf("%c", grid[i][j]);
                out.printf("\n");
            }

            for (int i = 0; i < 20; i++)
                out.printf("-");
            out.printf("\n");
        }

    }
}
