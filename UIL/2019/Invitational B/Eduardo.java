import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;

public class Eduardo {
    static Scanner in, input, sc;
    public static void main(String[] args) throws IOException {
        in = input = sc = new Scanner(new File("eduardo.dat"));

        while (in.hasNextLine()) {
            String line = in.nextLine();
            String[] words = line.trim().split("\\s+");
            int shift = words[0].length();
            for (int i = 0; i < line.length(); i++) {
                if (line.charAt(i) >= 'a' && line.charAt(i) <= 'z')
                    out.printf("%c", (char) ((line.charAt(i) - 'a' + shift) % 26 + 'a'));
                else if (line.charAt(i) >= 'A' && line.charAt(i) <= 'Z')
                    out.printf("%c", (char) ((line.charAt(i) - 'A' + shift) % 26 + 'A'));
                else
                    out.printf("%c", line.charAt(i));
            }
            out.printf("\n");
        }

    }
}
