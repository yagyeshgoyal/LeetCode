class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n =grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    count++;
                }
                else if(grid[i][j] == 2){
                    visited[i][j] = 1;
                    q.push({i,j});
                    count++;
                }
            }
        }
        int time = -1;
        while(!q.empty()){
            int p = q.size();
            time++;
            while(p--){
                auto front = q.front();
                int i= front.first;
                int j = front.second;
                q.pop();


                count--;

                if(i-1>=0 && visited[i-1][j] == 0 && grid[i-1][j] == 1){
                    q.push({i-1,j});
                    visited[i-1][j] = 1;
                }

                if(j-1>=0 && visited[i][j-1] == 0 && grid[i][j-1] == 1){
                    visited[i][j-1] = 1;
                    q.push({i,j-1});
                }

                if(i+1<n && visited[i+1][j] == 0 && grid[i+1][j] == 1){
                    visited[i+1][j] = 1;
                    q.push({i+1,j});
                }

                if(j+1<m && visited[i][j+1] == 0 && grid[i][j+1] == 1){
                    visited[i][j+1] = 1;
                    q.push({i,j+1});
                }
            }
        }

        if(count>0){
            return -1;

        }

        return max(0,time);


    }
};