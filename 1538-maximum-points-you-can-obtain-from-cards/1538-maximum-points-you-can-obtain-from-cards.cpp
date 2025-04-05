class Solution {
    int findans(int s, int e , int n, vector<int>&v, int k,vector<vector<int>>&dp){
        if(n-e-1 + s == k){
            return 0;
        }

        if(dp[s][e] != -1){
            return dp[s][e];
        }

        int ans1 = v[s] + findans(s+1,e,n,v,k,dp);
        int ans2 = v[e] + findans(s,e-1,n,v,k,dp);

        return dp[s][e] = max(ans1,ans2);
    }
    int findans(int s, int e , int n, vector<int>&v, int k,map<string,int>&dp){
        if(n-e-1 + s == k){
            return 0;
        }

        string temp = to_string(s) +"#"+to_string(e);

        if(dp.count(temp)){
            return dp[temp];
        }

        int ans1 = v[s] + findans(s+1,e,n,v,k,dp);
        int ans2 = v[e] + findans(s,e-1,n,v,k,dp);

        return dp[temp] = max(ans1,ans2);
    }
    int findans(int s, int e , int n, vector<int>&v, int k,unordered_map<int,unordered_map<int,int>>&dp){
        if(n-e-1 + s == k){
            return 0;
        }


        if(dp.count(s) && dp[s].count(e)){
            return dp[s][e];
        }

        int ans1 = v[s] + findans(s+1,e,n,v,k,dp);
        int ans2 = v[e] + findans(s,e-1,n,v,k,dp);

        return dp[s][e] = max(ans1,ans2);
    }
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        // vector<vector<int>>dp(cardPoints.size(), vector<int>(cardPoints.size(),-1));
        // unordered_map<int,unordered_map<int,int>>dp;
        // map<string,int>dp;
        // return findans(0,cardPoints.size()-1,cardPoints.size(), cardPoints,k,dp);

        int n = cardPoints.size();
        vector<int>prefix(n+1,0);
        vector<int>sufix(n+1,0);

        for(int i=0; i<n; i++){
            prefix[i+1] = cardPoints[i] + prefix[i];
        }

        for(int i=n-1; i>=0; i--){
            sufix[i] = cardPoints[i] + sufix[i+1];
        }

        int ans = 0;

        for(int i=0; i<=min(k,n); i++){
            ans = max(ans, prefix[i] + sufix[n-max(0,k-i)]);
            // cout<<ans<<endl;
        }

        return ans;
    }
};