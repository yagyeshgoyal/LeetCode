class Solution {
    private:
    const long long mod = 1e9+7;
    long long findlist(int n,int index, vector<vector<vector<long long>>>&dp,int late, int absent){
        if(absent >= 2 || late >= 3){
            return 0;
        }

        if(index == n){
            return 1;
        }

        if(dp[index][absent][late] != -1){
            return dp[index][absent][late];
        }

        long long ans = findlist(n,index+1,dp,0,absent);
        long long ans2 = 0;
        if(late<2)
        ans2 = findlist(n,index+1,dp,late+1,absent);
        
        if(absent == 0)
        ans = ans + findlist(n,index+1,dp,0,absent+1);

        dp[index][absent][late] = (ans + ans2)%mod;

        return (ans + ans2)%mod;
    }
public:
    int checkRecord(int n) {
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(2,vector<long long>(3,-1)));

        long long ans = findlist(n,0,dp,0,0);

        return ans;
    }
};