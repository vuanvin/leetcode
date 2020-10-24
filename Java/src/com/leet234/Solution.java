package com.leet234;

import com.leetcode.ListNode;

public class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null) return true;
        ListNode tail = null, p, q;
        p = q = head;
        while (q != null) {
            p = p.next;
            q = q.next;
            if (q != null) q = q.next;
        }
        q = null;
        while (p != null) {
            tail = p;
            p = p.next;
            tail.next = q;
            q = tail;
        }
        while (tail != null) {
            if (tail.val != head.val) return false;
            tail = tail.next;
            head = head.next;
        }
        return true;
    }
}
