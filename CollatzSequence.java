import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class CollatzSequence {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Введите степень x (для 10^x): ");
        int x = scanner.nextInt();
        int limit = (int) Math.pow(10, x);

        try (BufferedWriter writer = new BufferedWriter(new FileWriter("collatz_sequence.txt"))) {
            for (int i = 1; i <= limit; i++) {
                writer.write("Collatz sequence for " + i + ": ");
                writer.write(getCollatzSequence(i));
                writer.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        scanner.close();
    }

    @org.jetbrains.annotations.NotNull
    private static String getCollatzSequence(int n) {
        StringBuilder sequence = new StringBuilder();
        while (n != 1) {
            sequence.append(n).append(" -> ");
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = 3 * n + 1;
            }
        }
        sequence.append(1);
        return sequence.toString();
    }
}
