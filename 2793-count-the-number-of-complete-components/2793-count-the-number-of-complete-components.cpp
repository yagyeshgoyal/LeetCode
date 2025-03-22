class Solution {
    void dfs(int node, map<int,vector<int>>&adj, vector<int>&temp, vector<bool>&visited){
        visited[node] = true;
        temp.push_back(node);

        for(auto i : adj[node]){
            if(visited[i] == false){
                dfs(i,adj,temp,visited);
            }
        }

        return ;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        map<int,vector<int>>adj;
        for(int i=0; i<n; i++){
            adj[i] = {};
        }
        for(auto i :  edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        int ans = 0;
        vector<bool>visited(n,false);
        for(int i=0; i<n; i++){
            vector<int>temp;
            if(visited[i] == false){
                dfs(i,adj,temp,visited);
            }
            else{
                // cout<<"k"<<endl;
                continue;
            }

            bool flage = true;

            for(int j=0; j<temp.size(); j++){
                if(adj[temp[j]].size() != temp.size()-1){
                    flage = false;
                    break;
                }
            }

            if(flage){
                ans++;
            }
            temp.clear();
        }

        return ans;
        

    }
};