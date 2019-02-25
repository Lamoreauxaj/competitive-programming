import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;

public class Mary {
    static Scanner in, input, sc;

    public static int dist (String s, char c) {
        if (s.indexOf(c) == -1) return 100000;
        return min(s.indexOf(c), s.length()-s.lastIndexOf(c));
    }

    public static void main(String[] args) throws IOException {
        in = input = sc = new Scanner(new File("mary.dat"));
        
        int times = input.nextInt();
        
        while (times-->0) {
            int n = input.nextInt();
            String [] v = new String[n];

            for (int i = 0; i < n; i++) {
                v[i] = input.next().toUpperCase();
            }

            int cost = 0;
            String s = "";

            for (int i = 0; i < (n+1)/2; i++) {
                int j = n - i - 1;

                int mcost = 10000000;
                char best = '~';

                for (char c : v[i].toCharArray()) {
                    int cand = dist(v[i], c) + dist(v[j], c);
                    if (cand < mcost) {
                        mcost = cand;
                        best = c;
                    }
                    if (mcost == cand) {
                        if (c < best)
                            best = c;
                    }
                }
                cost += mcost;
                s += best;
            }

            for (int i = (n+1)/2; i < n; i++) {
                s += s.charAt(n - i - 1);
            } 

            if (cost > 10000) {
                out.println("IMPOSSIBLE");
            } else {
                out.println(s + " " + cost);
            }
        } 

    }
}
