class Solution {
    int findans(int i, int n, vector<int>&v, map<int,int>&mp, vector<int>&dp){
        if(i>=n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int ans1 = findans(i+1, n, v, mp,dp);
        int ans2 = v[i]*mp[v[i]];

        if(i+1<n && v[i]+1 == v[i+1]){
            ans2 = ans2 + findans(i+2,n,v,mp,dp);
        }
        else{
            ans2 = ans2 + findans(i+1,n,v,mp,dp);
        }

        return dp[i] = max(ans1,ans2);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>mp;
        for(auto i : nums){
            mp[i]++;
        }
        vector<int>v;
        for(auto i : mp){
            v.push_back(i.first);
        }

        sort(v.begin(),v.end());
        vector<int>dp(v.size()+1, -1);
        int ans = findans(0,v.size(),v,mp,dp);

        return ans;
    }
};