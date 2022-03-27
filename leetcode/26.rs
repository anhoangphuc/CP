use std::convert::TryInto;

struct Solution;

impl Solution {
    pub fn remove_duplucates(nums: &mut Vec<i32>) -> i32 {
        if nums.len() == 0 {
            return 0;
        }
        let mut cnt = 1;
        for i in 0..nums.len() - 1 {
            if nums[i] != nums[i + 1] {
                nums[cnt] = nums[i + 1];
                cnt += 1;
            }
        } 
        return cnt.try_into().unwrap();
    }
}

fn main() {
    let mut nums = vec![2, 7, 7, 8];
    let res = Solution::remove_duplucates(&mut nums);
    println!("{}", res);
}

#[test]
fn test() {
    let mut nums = vec![2, 7, 7, 8];
    assert_eq!(Solution::remove_duplucates(&mut nums), 3);
}
