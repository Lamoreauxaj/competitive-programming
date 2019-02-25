import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;

public class Alfonso {
    static Scanner in, input, sc;
    public static void main(String[] args) throws IOException {
        // in = input = sc = new Scanner(new File("al.dat"));

        String s = "ACEGIKMOQSUWY";
        for (int i = 0; i < s.length(); i += 2) {
            for (int j = i; j < s.length(); j++) {
                out.println(s.substring(j));
            }
        }

    }
}
