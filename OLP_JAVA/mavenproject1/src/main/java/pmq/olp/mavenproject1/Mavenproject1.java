/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

//package pmq.olp.mavenproject1;
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
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int x = Integer.parseInt(sc.next());
        int[] prices = new int[n];
        int[] pages = new int[n];
        for(int i = 0;i < n;i++){
            prices[i] = sc.nextInt();
        }
        for(int i = 0;i < n;i++){
           pages[i] = sc.nextInt();
        }
        int[][] dp = new int[n + 1][x + 1];
        for(int i = 0;i < n + 1;i++){
            Arrays.fill(dp[i], 0);
        }
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= x;j++){
                dp[i][j] = dp[i - 1][j];
                int left = j - prices[i - 1];
                if(left >= 0){
                    dp[i][j] = Math.max(dp[i][j],dp[i - 1][left] + pages[i - 1]);
                }
            }
        }
        System.out.println(dp[n][x]);
    }
}
