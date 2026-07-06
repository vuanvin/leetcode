use crate::leetcode::Solution;

impl Solution {
    pub fn find_words(words: Vec<String>) -> Vec<String> {
        let mut ans = Vec::<String>::new();
        let keyboard = vec!["qwertyuiop", "asdfghjkl", "zxcvbnm"];
        let keyboard = keyboard
            .into_iter()
            .map(|kb| kb.chars().collect::<Vec<_>>())
            .collect::<Vec<_>>();

        for word in words {
            let mut line = 0;
            let word_list = word.clone().to_lowercase().chars().collect::<Vec<_>>();
            for i in 0..3 {
                let ch = word_list.get(0).unwrap();
                if keyboard[i].contains(ch) {
                    line = i;
                    break;
                }
            }
            let mut key = true;
            for w in word_list {
                if !keyboard[line].contains(&w) {
                    key = false;
                    break;
                }
            }
            if key {
                ans.push(word);
            }
        }
        ans
    }
}
