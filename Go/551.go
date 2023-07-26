package leetcode

func checkRecord(s string) bool {
	absent, late := 0, 0
	for _, v := range s {
		switch byte(v) {
		case 'A':
			absent++
			if absent >= 2 {
				return false
			}
			late = 0
		case 'L':
			late++
			if late >= 3 {
				return false
			}
		default:
			late = 0
		}
	}
	return true
}
