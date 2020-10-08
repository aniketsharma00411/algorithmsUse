class Solution {
public:
    int ans;
    int solve(vector<int>& coins, int n, int cnt, vector<int>& dp) {
        if(n == 0) {
            return 0;
        }
       
        if(dp[n] != -1) {
            return dp[n];
        }
        int ans = INT_MAX;
        for(int i=0; i<coins.size(); i++) {
            if(coins[i] > n) {
                continue;
            }
            int val = solve(coins, n-coins[i], cnt+1, dp);
            if(val < ans) {
                ans = val;
            }
        }
        if(ans != INT_MAX) {
            ans = ans + 1;
        }
        dp[n] = ans;
        return dp[n];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) {
            return 0;
        }
        ans = INT_MAX;
        vector<int> dp;
        for(int i=0; i<=amount; i++) {
            dp.push_back(-1);
        }
        solve(coins, amount, 0, dp);
        if(dp[amount] == INT_MAX) {
          return -1;
        }
        return dp[amount];
    }
};
