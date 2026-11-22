class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        if (matrix.empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();
        
        int top = 0, bottom = m - 1;
        int height_mid = 0;
        while (top <= bottom) {
            height_mid = (top + bottom) / 2;
            if (target < matrix[height_mid][0]) {
                bottom = height_mid - 1;
            } else if (target >= matrix[height_mid][0]) {
                if (target > matrix[height_mid][n-1]) {
                    top = height_mid + 1;
                } else if (target <= matrix[height_mid][n-1]) {
                    break;
                }
            }
        }

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target < matrix[height_mid][mid]) {
                right = mid-1;
            } else if (target > matrix[height_mid][mid]) {
                left = mid + 1;
            } else if (target == matrix[height_mid][mid]) {
                return true;
            }
        }
        return false;
    }
};