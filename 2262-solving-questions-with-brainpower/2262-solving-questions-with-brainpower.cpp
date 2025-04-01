class Solution {
    long long findans(int i, vector<vector<int>>& questions,vector<long long int>&dp){
        if(i>=questions.size()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        long long int ans = questions[i][0] + findans(i+questions[i][1]+1, questions,dp);

        ans  = max(ans, findans(i+1,questions,dp));

        return dp[i] = ans;
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        
        vector<long long int>dp(questions.size()+1,-1);
        long long int ans = findans(0,questions,dp);

        return ans;
    }
};