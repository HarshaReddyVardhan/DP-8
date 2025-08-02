// Time Complexity: O(n)
// Space Complexity: O(n) — for dp[] array

class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        if (n < 3) return 0; // Not enough elements for a slice

        int[] dp = new int[n]; // dp[i] stores count of slices ending at i

        for (int i = 0; i < n - 2; i++) {
            // Check if nums[i], nums[i+1], nums[i+2] form an arithmetic slice
            if (nums[i + 1] - nums[i] == nums[i + 2] - nums[i + 1]) {
                dp[i + 2] = dp[i + 1] + 1;
            }
        }

        // Sum all dp values
        int sum = 0;
        for (int count : dp) {
            sum += count;
        }

        return sum;
    }
}
