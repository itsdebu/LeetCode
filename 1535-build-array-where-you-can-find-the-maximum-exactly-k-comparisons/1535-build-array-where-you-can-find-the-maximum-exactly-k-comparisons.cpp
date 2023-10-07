class Solution {
public:
    const int MOD = 1e9+7;
    int dp[51][101][51];
    int ways(int index, int mx, int n, int m, int temp_k, int orig_k) {
        if (index == n) {
            return (temp_k == orig_k) ? 1 : 0;
        }
        
        if (dp[index][mx][temp_k] != -1) {
            return dp[index][mx][temp_k] % MOD;
        }
        
        int count = 0;
        for (int i = 1; i <= m; i++) {
            if (i > mx) {
                count = (count + ways(index + 1, i, n, m, temp_k + 1, orig_k)) % MOD;
            } else {
                count = (count + ways(index + 1, mx, n, m, temp_k, orig_k)) % MOD;
            }
        }
        
        return dp[index][mx][temp_k] = count % MOD;
        // return count;
    }
    
    int numOfArrays(int n, int m, int k) {
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        memset(dp,-1,sizeof(dp));
        int count = ways(0, 0, n, m, 0, k) % MOD;
        return count % MOD;
    }
};
