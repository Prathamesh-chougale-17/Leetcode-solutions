impl Solution {
    pub fn sort_array(nums: Vec<i32>) -> Vec<i32> {
        if nums.is_empty() {
            return vec![];
        }

        let min_val = *nums.iter().min().unwrap();
        let max_val = *nums.iter().max().unwrap();
        let range = (max_val - min_val + 1) as usize;

        let mut freq = vec![0; range];

        for &num in &nums {
            freq[(num - min_val) as usize] += 1;
        }

        let mut sorted = Vec::with_capacity(nums.len());
        for (i, &count) in freq.iter().enumerate() {
            for _ in 0..count {
                sorted.push(i as i32 + min_val);
            }
        }

        sorted
    }
}
