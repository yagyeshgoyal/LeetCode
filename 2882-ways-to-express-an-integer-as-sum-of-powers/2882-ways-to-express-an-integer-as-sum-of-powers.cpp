class Solution {
    int mod = 1e9+7;

    int findways(int v, long long int n , int x, vector<vector<int>>&dp){
        if(n==0){
            return 1;
        }

        if(v>n || n<0){
            return 0;
        }

        if(dp[v][n] != -1){
            return dp[v][n];
        }

        long long int ans = findways(v+1,1ll*n-powl(v,x), x,dp);
        ans = (ans + findways(v+1,n,x,dp))%mod;

        return dp[v][n] =  ans;
    }

public:
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans = findways(1,n,x,dp);

        return ans;
    }
};