package com.leetcode;

import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        System.out.println(">>> Welcome to Java!");
        Solution solution = new Solution();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter here: ");

        String str = scanner.nextLine();
        String p = scanner.nextLine();
        System.out.println(solution.isMatch(str, p));

        System.out.println(">>> Bye. Good Luck!");
    }

}
