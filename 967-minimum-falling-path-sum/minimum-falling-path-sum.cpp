class Solution {

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++)
            dp[0][j] = matrix[0][j];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int st = matrix[i][j] + dp[i - 1][j];
                int ld = matrix[i][j];
                if (j - 1 >= 0)
                    ld += dp[i - 1][j - 1];
                else {
                    ld += 1e9;
                }

                int rd = matrix[i][j];
                if (j + 1 < m)
                    rd += dp[i - 1][j + 1];
                else {
                    rd += 1e9;
                }
                dp[i][j] = min(st, min(ld, rd));
            }
        }
        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            int ans = dp[n - 1][j];
            mini = min(mini, ans);
        }
        return mini;
    }
};