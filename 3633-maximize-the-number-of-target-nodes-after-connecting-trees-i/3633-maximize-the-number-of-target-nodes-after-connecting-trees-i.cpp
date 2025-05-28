class Solution {
    int countnode(int node, map<int,vector<int>>&adj, vector<bool>&visited, int k ){
        if(k<= 0){
            return 0;
        }
        visited[node] = true;
        int maxi = 0;

        for(auto i : adj[node]){
            if(visited[i] == false){
                int ans = countnode(i,adj,visited,k-1)+1;
                maxi = maxi + ans;
            }
        }

        visited[node] = false;
        return maxi;

        
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        map<int,vector<int>>adj2;
        for(auto i : edges2){
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }
        map<int,vector<int>>adj1;
        for(auto i : edges1){
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }
        int maxi = 0;
        vector<bool>visited2(edges2.size()+1,false);
        vector<bool>visited1(edges1.size()+1,false);

        for(int i=0; i<=edges2.size(); i++){
            int ans = countnode(i,adj2,visited2,k-1) + 1;
            maxi = max(maxi, ans);
        }

        if(k == 0){
            maxi = 0;
        }
        vector<int>ans(edges1.size()+1,0);
        for(int i=0; i<=edges1.size(); i++){
            int p = countnode(i,adj1,visited1,k) + 1;
            ans[i] = p + maxi;
        }

        return ans;
    }
};