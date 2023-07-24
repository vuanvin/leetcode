package leetcode

func detectCapitalUse(word string) bool {
	state := -1
	for _, v := range word {
		if v <= 'Z' {
			switch state {
			case 0:
				return false
			case -1:
				state = 1
			case 1:
				state = 2
			}
		} else {
			switch state {
			case -1:
				state = 0
			case 1:
				state = 0
			case 2:
				return false
			}
		}
	}
	return true
}
