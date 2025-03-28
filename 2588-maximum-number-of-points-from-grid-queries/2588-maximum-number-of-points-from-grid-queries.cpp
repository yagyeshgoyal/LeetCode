class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size();
        int m = grid[0].size();
        int k = queries.size();

        vector<pair<int,int>>v;
        for(int i = 0; i<k; i++){
            v.push_back({queries[i], i});
        }

        sort(v.begin(), v.end());

        vector<int>ans(k,0);
        int count = 0;
        // queue<pair<int,int>>q;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>>pq;
        pq.push({grid[0][0],{0,0}});

        vector<vector<bool>>visited(n,vector<bool>(m,false));
        visited[0][0] = true;

        for(int i=0; i<k; i++){
            int a = v[i].first;
            int b = v[i].second;
            
            while(!pq.empty() && pq.top().first<a){
                auto p = pq.top();
                pq.pop();
                count++;
                
                if(p.second.first-1>=0 && visited[p.second.first-1][p.second.second] == false){
                    visited[p.second.first-1][p.second.second] = true;
                    pq.push({grid[p.second.first-1][p.second.second],{p.second.first-1,p.second.second}});
                }
                if(p.second.first+1<n && visited[p.second.first+1][p.second.second] == false){
                    visited[p.second.first+1][p.second.second] = true;
                    pq.push({grid[p.second.first+1][p.second.second] ,{p.second.first+1,p.second.second}});
                }
                if(p.second.second-1>=0 && visited[p.second.first][p.second.second-1] == false){
                    visited[p.second.first][p.second.second-1] = true;
                    pq.push({grid[p.second.first][p.second.second-1],{p.second.first,p.second.second-1}});
                }
                if(p.second.second+1<m && visited[p.second.first][p.second.second+1] == false){
                    visited[p.second.first][p.second.second+1] = true;
                    pq.push({grid[p.second.first][p.second.second+1],{p.second.first,p.second.second+1}});
                }
                    
                
                
            }

            ans[b] =count;
            // cout<<count<<endl;

        }

        return ans;
    }
};