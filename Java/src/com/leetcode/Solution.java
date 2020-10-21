package com.leetcode;

import javax.swing.text.Style;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public String intToRoman(int num) {
        String res = new String();

        char[] chars = new char[]{'M',  'D', 'C', 'L', 'X', 'V', 'I'};
        int[] vals = new int[]   {1000, 500, 100, 50,  10,   5,   1, -1};
        int[] repl = new int[]   {2,    2,   4,   4,   6,    6,   7};

        for (int i = 0; i < 7; i++) {
            String str = new String();
            int n = num / vals[i];
            num -= (n * vals[i]);

            if (num >= vals[i] - vals[repl[i]]) {
                str += chars[repl[i]];
                str += chars[i];
                num -= (vals[i] - vals[repl[i]]);
            }

            for (int j = 0; j < n; j++) str = chars[i] + str;

            res += str;
        }

        return res;
    }

    public boolean isValidSudoku(char[][] board) {

        for (int i = 0; i < 9; i++) {
            int[] num = new int[9];
            for (int k = 0; k < 9; k++) num[k] = 0;

            for (int j = 0; j < 9; j++){
                char ch = board[i][j];
                if (ch != '.'){
                    if (num[ch-'0'-1] >= 1) {
                        return false;
                    } else {
                        num[ch-'0'-1] ++;
                    }
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            int[] num = new int[9];
            for (int k = 0; k < 9; k++) num[k] = 0;

            for (int j = 0; j < 9; j++){
                char ch = board[j][i];
                if (ch != '.'){
                    if (num[ch-'0'-1] >= 1) {
                        return false;
                    } else {
                        num[ch-'0'-1] ++;
                    }
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            int[] num = new int[9];
            for (int k = 0; k < 9; k++) num[k] = 0;

            for (int j = 0; j < 9; j++){
                int addi = i / 3;
                int addj = i % 3;

                char ch = board[addi * 3 + (j / 3)][addj * 3 + (j % 3)];
                if (ch != '.'){
                    if (num[ch-'0'-1] >= 1) {
                        return false;
                    } else {
                        num[ch-'0'-1] ++;
                    }
                }
            }
        }

        return true;
    }

    public String countAndSay(int n) {
        String str = "1";

        for (int i = 0; i < n - 1; i++) {
            String tmp = new String();
            for (int j = 0; j < str.length(); ) {
                char ch = str.charAt(j++);
                int cnt = 1;
                while(j < str.length() && ch == str.charAt(j)) {
                    j++;
                    cnt ++;
                }
                tmp = tmp + cnt + ch;
            }
            str = tmp;
        }
        return str;
    }

    public int[][] merge(int[][] intervals) {
        int[][] res = new int[intervals.length][];
        int sz = 0;

        for (int i = 0; i < intervals.length; i++) {

            int minVal = intervals[0][0];
            int minId = 0;
            for (int j = 0; j < intervals.length - i; j ++) {
                if (intervals[j][0] < minVal) {
                    minVal = intervals[j][0];
                    minId = j;
                }
            }
            int[] tmp = intervals[minId];
            intervals[minId] = intervals[intervals.length - i - 1];

            if (i == 0 || res[sz-1][1] < tmp[0]) {
                res[sz ++] = tmp.clone();
            } else {
                res[sz-1][1] = Math.max(tmp[1], res[sz-1][1]);
            }
        }
        int[][] result = new int[sz][];
        for(int i = 0; i < sz; i++) result[i] = res[i];

        return result;
    }

    public String simplifyPath(String path) {
        String[] strs = path.split("/");
        String res = new String("");
        int[] tags = new int[strs.length];
        Arrays.fill(tags, -1);

        int pt = -1;
        for (int i = 0; i < strs.length; i++) {
            // System.out.println(strs[i]);
            if (strs[i].equals("") || strs[i].equals(".")) {

            } else if (strs[i].equals("..")) {
                if(pt != -1) pt = tags[pt];
            } else {
                tags[i] = pt;
                pt = i;
            }
        }

        while(pt >= 0) {
            res = strs[pt] + res;
            pt = tags[pt];
            if (!res.equals("")) res = "/" + res;
        }
        if (res.equals("")) res = "/" + res;

        return res;
    }

    public String convert(String s, int numRows) {
        if (numRows == 1) return s;
        String res = new String();
        for (int i = 0; i < numRows; i++) {
            int pt = i;
            int level = i;
            while (pt < s.length()) {
                res += s.charAt(pt);
                // down
                pt += (numRows - level - 1);
                // up
                pt += (numRows - level - 1);
                if (level != 0 &&  level+1 != numRows && pt < s.length()) res  += s.charAt(pt);

                // up
                pt += level;
                // down
                pt += level;
            }
        }
        return  res;
    }

    public int myAtoi(String str) {
        boolean singed = false;
        int beginIndex = 0;
        while(beginIndex < str.length() && str.charAt(beginIndex) == ' ') { beginIndex++; }

        int sn = 0;
        if (beginIndex == str.length()) return 0;
        if (str.charAt(beginIndex) == '-') {
            singed = true;
            beginIndex ++;
            sn ++;
        }
        if (beginIndex == str.length()) return 0;
        if (str.charAt(beginIndex) == '+') {
            beginIndex++;
            sn ++;
        }
        if (sn >= 2) return 0;

        if (str.length() < beginIndex + 1) return 0;

        int endIndex = beginIndex;
        while (endIndex < str.length() && str.charAt(endIndex) >= '0' && str.charAt(endIndex) <= '9') {
            endIndex ++;
        }
        if (endIndex == beginIndex) return 0;
        while(beginIndex < endIndex && str.charAt(beginIndex) == '0') beginIndex ++;

        str = str.substring(beginIndex, endIndex);
        if (singed && str.length() >= 10 && str.compareTo("2147483648") > 0) return -2147483648;
        if (!singed && str.length() >= 10 && str.compareTo("2147483647") > 0) return 2147483647;
        if (singed && str.length() > 10) return -2147483648;
        if (!singed && str.length() > 10) return 2147483647;

        int res = 0;
        for (int i = 0; i < str.length(); i++) {
            res *= 10;
            res += (str.charAt(i) - '0');
        }
        res = singed ? -res : res;

        return res;
    }

    public int reverse(int x) {
        boolean signed = (x < 0);
        String str = String.valueOf(x);
        String res = new String();
        int beginIndex = 0;
        if (signed) {
            res += "-";
            beginIndex = 1;
        }

        for (int i = 0; i < str.length() - beginIndex; i++) {
            res += str.charAt(str.length() - i - 1);
        }
        if (!signed) {
            if (res.length() == 10 && res.compareTo(String.valueOf( (1 << 31) - 1 )) > 0) {
                return 0;
            }
            if (res.length() > 10) return 0;
        }
        if (signed) {
            if (res.length() == 11 && res.compareTo(String.valueOf( (1 << 31))) > 0) {
                return 0;
            }
            if (res.length() > 11) return 0;
        }

        return Integer.valueOf(res);
    }

    public boolean isPalindrome(int x) {
        String str = String.valueOf(x);
        for (int i = 0; i < str.length() / 2 + 1; i++) {
            if (str.charAt(i) != str.charAt(str.length() - i - 1)) return false;
        }
        return true;
    }

    public boolean nonIsMatch(String s, String p) {
        if (s.length() == 0 && p.length() == 0) return true;
        if (s.length() == 0 || p.length() == 0) return false;
        if (p.charAt(0) == '*') {
            boolean tmp = false;
            for (int i = 1; i <= s.length(); i++) {
                tmp = tmp || isMatch(s.substring(i), p.substring(1));
            }
            return tmp;
        } else if (p.charAt(0) == '.') {
            return isMatch(s.substring(1), p.substring(1));
        } else {
            return (p.charAt(0) == s.charAt(0)) && isMatch(s.substring(1), p.substring(1));
        }
    }

    public int maxArea(int[] height) {
        int i = 0, j = height.length-1;
        int maxVal = 0;
        while(i < j) {
            maxVal = Math.max(Math.min(height[i], height[j]) * (j - i), maxVal);
            if (height[i] < height[j]) {
                i++;
                while(i < j && height[i] <= height[i-1]) i++;
            }
            else {
                j--;
                while (i < j && height[j] <= height[j+1]) j--;
            }
        }
        return maxVal;
    }

    public List<String> generateParenthesis(int n) {
        List<String> list = new ArrayList<>();
        StringBuilder builder = new StringBuilder();
        int plusTime = 3;
        while(plusTime > 0) {
            builder.append('(');
        }

        return list;
    }

    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int res = 0;

        return res;
    }

    public int trap(int[] height) {
        int maxVal = 0;
        int sum = 0;
        for (int h : height) maxVal = Math.max(h, maxVal);
        int l = 0, r = height.length-1;
        while (l+1 < height.length && height[l] <= height[l+1]) l++;
        while (r-1 >= 0 && height[r] <= height[r-1]) r--;
        while (l < r) {
            if (height[l] <= height[r]) {
                int i = l + 1;
                while (height[i] < height[l]) {
                    sum -= height[i];
                    i++;
                }
                sum += height[l] * (i - l - 1);
                l = i;
                while (l+1 < height.length && height[l] <= height[l+1]) l++;
            } else {
                int i = r - 1;
                while (height[i] < height[r]) {
                    sum -= height[i];
                    i--;
                }
                sum += height[r] * (r - i - 1);
                r = i;
                while (r-1 >= 0 && height[r] <= height[r-1]) r--;
            }
        }

        return sum;
    }

    public String longestCommonPrefix(String[] strs) {
        int i = 0;
        while (i < strs[0].length()) {
            boolean b = true;
            for (int j = 1; j < strs.length; j++) {
                if (strs[0].charAt(i) != strs[j].charAt(i)) b = false;
            }
            if (!b) break;
            i ++;
        }
        return strs[0].substring(0, i);
    }

    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] res = new int[nums.length-k+1];
        int maxPos = 0;
        for (int j = 1; j < k; j++) {
            if (nums[maxPos] <= nums[j]) maxPos = j;
        }
        res[0] = nums[maxPos];

        for (int i = 1; i < nums.length-k+1; i++) {
            if (maxPos == 0) {
                for (int j = 1; j < k; j++) {
                    if (nums[i + maxPos] <= nums[i + j]) maxPos = j;
                }
            }
            else {
                maxPos --;
                if (nums[i + maxPos] <= nums[i + k - 1]) {
                    maxPos = k - 1;
                }
            }
            res[i] = nums[i + maxPos];
        }

        return res;
    }

    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<String>();
        int n = digits.length();
        int[] state = new int[n];
        StringBuilder builder = new StringBuilder();
        int p = 0;

        while (p >= 0) {
            if (p == n) {
                res.add(builder.toString());
                p --;

            }


        }

        return res;
    }

    public boolean isMatch(String s, String p) {
        if (s.length() == 0 && p.length() == 0) return true;
        if (p.length() == 0) return false;
        if (p.length() > 1 && p.charAt(1) == '*') {
            if (s.length() == 0) return isMatch(s, p.substring(2));
            boolean tmp = p.charAt(0) == '.' || p.charAt(0) == s.charAt(0);
            return isMatch(s, p.substring(2)) || (tmp && isMatch(s.substring(1), p));
        } else if (s.length() == 0) {
            return false;
        } else {
            return (p.charAt(0) == '.' || p.charAt(0) == s.charAt(0)) && isMatch(s.substring(1), p.substring(1));
        }
    }

    
}

