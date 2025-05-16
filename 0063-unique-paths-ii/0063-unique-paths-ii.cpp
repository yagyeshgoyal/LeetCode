class Solution {
    int findpath(int i, int j, vector<vector<int>>&ob,vector<vector<bool>>&visited, vector<vector<int>>&dp){
        if(i==ob.size()-1 && j==ob[0].size()-1){
            
            return 1;
        }

        if(i>=ob.size() || j>= ob[0].size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        visited[i][j] = true;
        int ans = 0;
        if(j+1< ob[0].size() && ob[i][j+1] != 1 && visited[i][j+1] == false){
            ans = findpath(i,j+1,ob,visited,dp);
        }

        if(i+1< ob.size() && ob[i+1][j] != 1 && visited[i+1][j] == false){
            ans = ans + findpath(i+1,j,ob,visited,dp);
        }

        visited[i][j] = false;

        return dp[i][j] = ans;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // if(obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1 && obstacleGrid[0][0] == 1){
        //     return 0;
        // }
        int ans = 0;
        vector<vector<bool>>visited(obstacleGrid.size(), vector<bool>(obstacleGrid[0].size(),false));
        vector<vector<int>>dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(),-1));
        if(obstacleGrid[0][0] != 1)
        ans = findpath(0,0,obstacleGrid,visited,dp);

        return ans;
    }
};