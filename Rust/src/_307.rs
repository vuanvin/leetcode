struct NumArray {
    tr: Vec<i32>,
    n: usize,
}

impl NumArray {
    fn new(nums: Vec<i32>) -> Self {
        let mut tr = vec![0; nums.len() * 4];
        fn build(i: usize, l: usize, r: usize, tr: &mut Vec<i32>, nums: &Vec<i32>) -> i32 {
            if l + 1 == r {
                tr[i] = nums[l];
            } else {
                let m = (l + r) / 2;
                tr[i] = build(i * 2 + 1, l, m, tr, nums) + build(i * 2 + 2, m, r, tr, nums);
            }
            tr[i]
        }
        build(0, 0, nums.len(), &mut tr, &nums);
        Self { tr, n: nums.len() }
    }

    fn update(&mut self, index: i32, val: i32) {
        fn update_tree(idx: usize, v: i32, i: usize, l: usize, r: usize, tr: &mut Vec<i32>) -> i32 {
            if l + 1 == r {
                let ret = v - tr[i];
                tr[i] = v;
                return ret;
            }
            let m = (l + r) / 2;
            let ret = if idx < m {
                update_tree(idx, v, i * 2 + 1, l, m, tr)
            } else {
                update_tree(idx, v, i * 2 + 2, m, r, tr)
            };
            tr[i] += ret;
            return ret;
        }
        update_tree(index as usize, val, 0, 0, self.n, &mut self.tr);
    }

    fn sum_range(&self, left: i32, right: i32) -> i32 {
        fn query(x: usize, y: usize, i: usize, l: usize, r: usize, tr: &Vec<i32>) -> i32 {
            if x <= l && r <= y {
                return tr[i];
            }
            let m = (l + r) / 2;
            return if x < r && l < y {
                query(x, y, i * 2 + 1, l, m, tr) + query(x, y, i * 2 + 2, m, r, tr)
            } else {
                0
            };
        }
        query(left as usize, right as usize + 1, 0, 0, self.n, &self.tr)
    }
}
