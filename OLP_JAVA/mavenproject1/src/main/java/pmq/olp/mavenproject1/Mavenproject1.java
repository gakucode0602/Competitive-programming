/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package pmq.olp.mavenproject1;
import java.util.AbstractList;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
/**
 *
 * @author dangc
 */

public class Mavenproject1 {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[] dp = new int[n + 2];
        for(int j = 0;j <= n + 1;j++){
            dp[j] = (int)Math.pow(10,9);
        }
        dp[0] = 0;
        for(int x = 0;x <= n;x++){
            String s = Integer.toString(x);
            for(int d = 0;d < s.length();d++)
            {
                dp[x] = Math.min(dp[x],dp[x - (s.charAt(d) - '0')] + 1);
            }
        }
        System.out.println(dp[n]);
    }
}
