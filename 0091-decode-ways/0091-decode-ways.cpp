class Solution {
    int findans(int i, string s, vector<int>&dp){
        if(i >= s.length()){
            return 1;
        }

        // if(i == s.length()-1){
        //     return 1;
        // }

        if(dp[i] != -1){
            return dp[i];
        }
        int ans = 0;
        if(s[i]>'0')
         ans = findans(i+1,s,dp);

        if(i < s.length()-1){
            int k = (s[i]-'0')*10 + (s[i+1]-'0');

            if(k>=10 && k<=26){
                ans = ans + findans(i+2,s,dp);
            }
        }

        return dp[i] = ans;
    }
public:
    int numDecodings(string s) {
        vector<int>dp(s.length(),-1);
        int ans = findans(0,s,dp);

        return ans;
    }
};