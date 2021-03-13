package com.leet406;

import java.util.Arrays;
import java.util.Comparator;

public class Solution {
    class sortcmp implements Comparator<Integer[]> {
        public int compare(Integer[] a, Integer[] b) {
            return a[0] != b[0] ? a[0] - b[0] : a[1] - b[1];
        }
    }

    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, (a, b) -> { return a[1] != b[1] ? a[1] - b[1] : a[0] - b[0]; });
        int n = people.length;
        for (int i = 0; i < n-1; i++) {
            int j = i;
            while (people[j][0] >= people[j+1][0]) {
                int[] tmp = people[j];
                people[j] = people[j+1];
                people[j+1] = tmp;
                j ++;
            }
        }

        return people;
    }
}
