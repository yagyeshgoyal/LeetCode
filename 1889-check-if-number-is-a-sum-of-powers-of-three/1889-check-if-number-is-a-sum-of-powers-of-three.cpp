class Solution {

    bool getsum(int &n, int j, int sum,vector<vector<int>>&dp){
        if(sum == n){
            return true;
        }

        if(sum > n){
            return false;
        }

        if(j==15){
            return false;
        }

        if(dp[sum][j] != -1){
            return dp[sum][j];
        }

        int ans  = false;
        for(int i = j; i<15; i++){
            ans = ans || getsum(n,i+1,pow(3,i)+sum,dp);

            if(ans){
                return dp[sum][j] =  ans;
            }
        }

        return dp[sum][j] = ans;
    }
public:

    bool checkPowersOfThree(int n) {
        // vector<vector<int>>dp(n+1,vector<int>(16,-1));
        // return getsum(n,0,0,dp);
        unordered_map<int,bool>mp;
        int k =15;
        while(n!=0){
            int p = logf(n)/logf(3);
            if(mp[p]){
                p = k-1;
            }
            else{
                k = p;
                mp[p] = true;
            }

            n = n - pow(3,p);
            if(p<=0 && n != 0){
                return false;
            }
            
        }

        return true;
    }
};