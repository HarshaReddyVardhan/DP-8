// Time Complexity : O(n)
// Space Complexity : O(1) — constant space used

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int count = 0; // Current count of valid slices ending at i
        int sum = 0;   // Total number of slices

        // Start from index 0 to n - 3, as we check triplets
        for (int i = 0; i < n - 2; ++i) {
            // Check if three consecutive elements form arithmetic slice
            if (nums[i + 1] - nums[i] == nums[i + 2] - nums[i + 1]) {
                count += 1;      // One more slice ending at i+2
                sum += count;    // Add all slices ending here
            } else {
                count = 0;       // Reset if the slice breaks
            }
        }

        return sum;
    }
};
