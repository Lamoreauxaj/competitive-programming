import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.System.*;
import static java.lang.Math.*;

public class Sara {
    static Scanner in, input, sc;
    public static void main(String[] args) throws IOException {
        in = input = sc = new Scanner(new File("sara.dat"));

        int TC = in.nextInt(); in.nextLine();
        while (TC-- > 0) {
            String[] one = in.nextLine().trim().split("\\s+");
            String[] two = in.nextLine().trim().split("\\s+");
            TreeSet<String> setOne = new TreeSet<>();
            TreeSet<String> setTwo = new TreeSet<>();
            for (String s : one)
                setOne.add(s);
            for (String s : two)
                setTwo.add(s);
            TreeSet<String> total = new TreeSet<>();
            for (String s : one)
                total.add(s);
            for (String s : two)
                total.add(s);
            TreeSet<String> intersect = new TreeSet<>();
            for (String s : two)
                if (setOne.contains(s))
                    intersect.add(s);
            for (String s : intersect)
                setOne.remove(s);
            for (String s : intersect)
                setTwo.remove(s);

            if (total.size() == 0)
                total.add("none");
            if (setOne.size() == 0)
                setOne.add("none");
            if (setTwo.size() == 0)
                setTwo.add("none");
            if (intersect.size() == 0)
                intersect.add("none");

            out.printf("Guests:");
            for (String s : total)
                out.printf(" %s", s);
            out.printf("\n");
            out.printf("Guests of Both:");
            for (String s : intersect)
                out.printf(" %s", s);
            out.printf("\n");
            out.printf("Bride's Guests:");
            for (String s : setOne)
                out.printf(" %s", s);
            out.printf("\n");
            out.printf("Groom's Guests:");
            for (String s : setTwo)
                out.printf(" %s", s);
            out.printf("\n");
            for (int i = 0; i < 20; i++)
                out.printf("-");
            out.printf("\n");

        }

    }
}
