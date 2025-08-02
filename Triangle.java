// Time Complexity: O(n^2) — Every element is visited once.
// Space Complexity: O(1) — No extra space used (in-place update).
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();

        // Start from the second row and update in place
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                    // First element in the row: only one parent
                    triangle.get(i).set(j, triangle.get(i).get(j) + triangle.get(i - 1).get(0));
                } else if (j == i) {
                    // Last element in the row: only one parent
                    triangle.get(i).set(j, triangle.get(i).get(j) + triangle.get(i - 1).get(j - 1));
                } else {
                    // Middle elements: choose min of two parents
                    triangle.get(i).set(j, triangle.get(i).get(j) +
                        Math.min(triangle.get(i - 1).get(j), triangle.get(i - 1).get(j - 1)));
                }
            }
        }

        // Find the minimum value in the last row
        int min = triangle.get(n - 1).get(0);
        for (int i = 1; i < n; ++i) {
            min = Math.min(min, triangle.get(n - 1).get(i));
        }

        return min;
    }
}
