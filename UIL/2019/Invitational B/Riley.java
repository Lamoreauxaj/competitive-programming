import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;

public class Riley {
    static Scanner in, input, sc;
    public static void main(String[] args) throws IOException {
        in = input = sc = new Scanner(new File("riley.dat"));

        int TC = in.nextInt();
        while (TC-- > 0) {
            R = in.nextInt();
            C = in.nextInt();
            grid = new int[R][C];
            visit = new boolean[R][C];
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++)
                    grid[i][j] = in.nextInt();
            }

            ArrayList<Double> plots = new ArrayList<>();

            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (grid[i][j] != 0 && !visit[i][j]) {
                        plots.add(flood(i, j));
                    }
                }
            }

            Collections.sort(plots);
            double total = 0;
            for (Double d : plots)
                total += d;
            out.printf("%.2f acres\n", total);
            for (int i = plots.size() - 1; i >= 0; i--)
                out.printf("%.2f acres\n", plots.get(i));
            out.printf("============\n");
        }

    }

    static int R, C;
    static int[][] grid;
    static boolean[][] visit;

    static double flood(int r, int c) {
        if (r < 0 || c < 0 || r >= R || c >= C) return 0;
        if (grid[r][c] == 0) return 0;
        if (visit[r][c]) return 0;
        visit[r][c] = true;
        return grid[r][c] * .25 + flood(r + 1, c - 1) + flood(r + 1, c + 1) + flood(r, c + 1) + flood(r - 1, c)
            +  flood(r - 1, c + 1) + flood(r - 1, c - 1) + flood(r, c - 1) + flood(r + 1, c);
    }
}
