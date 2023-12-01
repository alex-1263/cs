import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // 找到相邻两名战士的战斗力差值中的最小值
    static int find(int n, int[] strengths) {
        if (n <= 1) {
            // 至少需要两名战士
            return -1;
        }

        // 先对战士的战斗力进行排序
        int[] sortedStrengths = Arrays.copyOf(strengths, n);
        Arrays.sort(sortedStrengths);

        // 初始最小差值为最大整数
        int minDifference = Integer.MAX_VALUE;

        // 找出相邻两名战士的战斗力差值中的最小值
        for (int i = 1; i < n; ++i) {
            int difference = sortedStrengths[i] - sortedStrengths[i - 1];
            minDifference = Math.min(minDifference, difference);
        }

        return minDifference;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("输入战士的数量 n：");
        int n = scanner.nextInt();

        int[] strengths = new int[n];
        System.out.println("输入每名战士的战斗力：");
        for (int i = 0; i < n; ++i) {
            strengths[i] = scanner.nextInt();
        }

        int result = find(n, strengths);

        if (result == -1) {
            System.out.println("战士数量不足，无法进行对比");
        } else {
            System.out.println("相邻两名战士的战斗力差值中的最小值为：" + result);
        }
    }
}
