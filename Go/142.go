package leetcode

func detectCycle(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	s, f := head, head
	for f != nil && f.Next != nil {
		s = s.Next
		f = f.Next.Next
		if s == f {
			break
		}
	}
	if f == nil || f.Next == nil {
		return nil
	}
	f = head
	for s != f {
		f = f.Next
		s = s.Next
	}
	return s
}
