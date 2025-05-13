class Solution {
    int findans(int i, int j , vector<vector<int>>& grid,vector<vector<int>>&dp){
        
        if(i>= grid.size() || j>= grid[0].size()){
            return 1500000;
        }

        if(i == grid.size() -1 && j == grid[0].size()-1 ){
            return grid[i][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans1  = findans(i+1, j, grid,dp);
        int ans2 = findans(i,j+1,grid,dp);

        return dp[i][j] = grid[i][j] + min(ans1,ans2);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {

        vector<vector<int>>dp(grid.size()+1 , vector<int>(grid[0].size()+1, -1));
        // int ans = findans(0,0,grid, dp);
        // return ans;
        vector<int>v;
        v.push_back(grid[0][0]);
        for(int i=1; i<grid[0].size(); i++){
            v.push_back(v[v.size()-1] + grid[0][i]);
        }

        vector<int>temp(v.size());
        for(int i=1; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(j==0){
                    temp[j] = v[j] + grid[i][j];
                }
                else{
                    temp[j] = grid[i][j] + min(v[j],temp[j-1]);
                }
            }
            v = temp;
        }

        return v[v.size()-1];
    }
};