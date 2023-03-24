import java.util.Scanner;
import java.math.BigInteger; // 1e5! exceed the limit of long long > use BigInteger

public class Main {

    private static final int MAX_DIff = 10;
    /*
     * a * (a + 1) * (a + 2) * ... * (b - 1) * b
     * = (a * (a + 1) * ... * mid) * ((mid + 1) * (mid + 2) * ... * b)
     * = sub_factorial(a, mid) * sub_factorial(mid + 1, b)
     */
    private static  BigInteger sub_factorial(int from, int to) { // divide and conquer
        int diff = to - from;
        // If the difference is smaller than the MAX_DIFF
        // calculate the factorial
        if (diff < MAX_DIff) {
            BigInteger rst = BigInteger.ONE;
            for (int i = from; i  < to + 1; ++i) { // calculate the factorial
                rst = rst.multiply(BigInteger.valueOf(i));
            }
            return rst;
        } else { // If the difference is bigger than the MAX_DIFF, divide to sub factorial
            int mid = (diff / 2) + from;
            return sub_factorial(from, mid).multiply(sub_factorial(mid + 1, to));
        }
    }
    private static BigInteger general_factorial(int num) {
        return sub_factorial(1, num + 1);
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt(); scan.nextLine();
        var ans = general_factorial(n);
        System.out.println(ans);
    }
}


