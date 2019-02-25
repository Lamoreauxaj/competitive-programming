import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;

public class Hyun {
    static Scanner in, input, sc;
    public static void main(String[] args) throws IOException {
        in = input = sc = new Scanner(new File("hyun.dat"));

        int TC = in.nextInt(); in.nextLine();
        for (int tc = 1; tc <= TC; tc++) {
            String line = in.nextLine();
            boolean top = false, home = false, bottom = false, number = false;
            for (int i = 0; i < line.length(); i++) {
                if ("qwertyuiop".contains("" + line.charAt(i))) top = true;
                else if ("asdfghjkl".contains("" + line.charAt(i))) home = true;
                else if ("zxcvbnm".contains("" + line.charAt(i))) bottom = true;
                else if ("0123456789".contains("" +line.charAt(i))) number = true;
            }
            out.printf("Case #%d:", tc);
            if (number) out.printf(" NUMBER");
            if (top) out.printf(" TOP");
            if (home) out.printf(" HOME");
            if (bottom) out.printf(" BOTTOM");
            out.printf("\n");
        }

    }
}
