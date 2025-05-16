class Solution {
    int findways(int i, int amount , vector<int>& coins, vector<vector<int>>&dp){
        if(amount == 0){
            return 1;
        }
        if(dp[amount][i] != -1){
            return dp[amount][i];
        }
        int ans = 0;
        for(int j=i; j<coins.size(); j++){
            if(coins[j]<=amount){
                ans = ans + findways(j,amount-coins[j],coins,dp);
            }
        }

        return dp[amount][i] = ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0){
            return 1;
        }
        int ans = 0;
        vector<vector<int>>dp(amount+1,vector<int>(coins.size(), -1));
        sort(coins.begin(), coins.end());

        for(int i=0; i<coins.size(); i++){
            if(coins[i] <= amount){
                ans = ans + findways(i,amount-coins[i],coins,dp);
            }
        }

        return ans;

    }
};