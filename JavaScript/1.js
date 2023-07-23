/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const hashMap = {};
    for (let r = 0; r < nums.length; r++) {
        const val = nums[r];
        const l = hashMap[target - val];
        if (l != undefined) {
            return [l, r];
        } else {
            hashMap[val] = r;
        }
    }
};