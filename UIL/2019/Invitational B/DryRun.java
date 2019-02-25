import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;

public class DryRun {
    static Scanner in, input, sc;
    public static void main(String[] args) throws IOException {
        in = input = sc = new Scanner(new File("dryrun.dat"));

        int TC = in.nextInt();
        while (TC-- > 0) {
            out.printf("I like %s.\n", in.next());
        }

    }
}
