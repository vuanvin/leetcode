package com.leet142

import com.leetcode.ListNode

object Solution {
  def detectCycle(head: ListNode): ListNode = {
    if (head == null || head.next == null) return null
    val head2 = fast(head.next, head.next.next)
    if (head2 == null) null else rev(head, head2, head, head2, head2)
  }
 
  def fast(p:ListNode, q:ListNode): ListNode = {
    if (q == null || q.next == null) null
    else if (p == q) p
    else fast(p.next, q.next.next)
  }

  def rev(p: ListNode, q:ListNode, ph: ListNode, qh: ListNode, nullNode: ListNode): ListNode = {
    if (p == q) p
    else {
      if (p.next == nullNode) {
        rev(qh, q.next, ph, qh, nullNode)
      } else if (q.next == nullNode) {
        rev(p.next, ph, ph, qh, nullNode)
      }
      else rev(p.next, q.next, ph, qh, nullNode)
    }
  }
}
