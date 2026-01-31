class Solution {

    int findans(int i,  int j, int &m, int &n , vector<vector<int>>&dp){
        if(i==m || j==n){
            return 0;
        }

        if(i==m-1 && j==n-1){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans1 = findans(i+1,j,m,n,dp);
        int ans2 = findans(i,j+1,m,n,dp);

        return dp[i][j] = ans1+ans2;
    }

    int findans1(int &m, int &n){
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                dp[i][j] = dp[i+1][j] + dp[i][j+1];

                if(i == m-1 && j==n-1){
                    dp[i][j] = 1;
                }
            }
        }

        return dp[0][0];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // int ans = findans(0,0,m,n,dp);

        int ans = findans1(m, n);

        return ans;
    }
};