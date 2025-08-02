// Time Complexity: O(n^2) — We process each triangle element once.
// Space Complexity: O(n^2) — Because of the 2D dp array.
//   Can be optimized to O(n) using a 1D array from bottom-up.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Allocate a 2D DP array
        int** dp = new int*[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = new int[i + 1];
        }

        // Initialize top of triangle
        dp[0][0] = triangle[0][0];

        // Fill DP table row by row
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                    dp[i][j] = triangle[i][j] + dp[i - 1][0]; // First element in row
                } else if (j == i) {
                    dp[i][j] = triangle[i][j] + dp[i - 1][j - 1]; // Last element in row
                } else {
                    dp[i][j] = triangle[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]); // Middle
                }
            }
        }

        // Find minimum in the last row
        int minVal = dp[n - 1][0];
        for (int i = 1; i < n; ++i) {
            minVal = min(minVal, dp[n - 1][i]);
        }

        // Cleanup (important to avoid memory leaks)
        for (int i = 0; i < n; ++i) {
            delete[] dp[i];
        }
        delete[] dp;

        return minVal;
    }
};
