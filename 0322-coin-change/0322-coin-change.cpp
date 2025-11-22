class Solution {
public:
    int solve(int i , int amount , vector<int>&coins, vector<vector<int>>&dp){
        if(i==0){
            if(amount%coins[i] == 0){
                return amount/coins[i];
            }
            return INT_MAX;
        }

        if(dp[amount][i] != -1){
            return dp[amount][i];
        }

        int nottake = 0 + solve(i-1,amount,coins,dp);
        int take = INT_MAX;

        if(coins[i]<= amount){
            int p = solve(i,amount-coins[i], coins,dp);
            if(p != INT_MAX){
                take = 1 + p;
            }
        }

        return dp[amount][i] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>>dp(amount+1,vector<int>(n,-1));
        int ans = solve(n-1,amount, coins,dp);

        if(ans>= INT_MAX){
            return -1;
        }

        return ans;
    }
};