class Solution {
    void colornode(int node, map<int,vector<int>>&adj, vector<bool>&visited, int flage, vector<bool>&color){
        
        visited[node] = true;
        color[node] = flage;
        int maxi = 0;

        

        for(auto i : adj[node]){
            if(visited[i] == false){
                colornode(i,adj,visited,!flage, color);
            }
        }

        visited[node] = false;
        

        
    }
    vector<vector<int>> buildList(const vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size() + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }

    void dfsColor(const vector<vector<int>>& adj, int u, int parent,
                  vector<int>& color, int& evenCnt, int& oddCnt) {
        if (color[u] == 0) evenCnt++;
        else oddCnt++;
        for (int v : adj[u]) if (v != parent) {
            color[v] = color[u] ^ 1;
            dfsColor(adj, v, u, color, evenCnt, oddCnt);
        }
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // map<int,vector<int>>adj2;
        // for(auto i : edges2){
        //     adj2[i[0]].push_back(i[1]);
        //     adj2[i[1]].push_back(i[0]);
        // }
        // map<int,vector<int>>adj1;
        // for(auto i : edges1){
        //     adj1[i[0]].push_back(i[1]);
        //     adj1[i[1]].push_back(i[0]);
        // }
        // int maxi = 0;
        // vector<bool>visited2(edges2.size()+1,false);
        // vector<bool>color2(edges2.size()+1,false);
        // vector<bool>visited1(edges1.size()+1,false);
        // vector<bool>color1(edges1.size()+1,false);

        
        // colornode(0,adj2,visited2,false,color2);
        // for(int i=0; i<edges2.size()+1; i++){
        //     if(color2[i] == true){
        //         maxi++;
        //     }
        // }
        // maxi = max<int>(maxi, edges2.size()+1-maxi);
        

        
        // cout<<maxi<<endl;
        // vector<int>ans(edges1.size()+1,0);
        
        // colornode(0,adj1,visited1,true,color1);
        // int counttrue = 0;
        // for(int i=0; i<color1.size(); i++){
        //     if(color1[i] == true){
        //         counttrue++;
        //     }
        // }

        // for(int i=0; i<color1.size(); i++){
        //     if(color1[i] == true){
        //         ans[i] = counttrue + maxi;
        //     }
        //     else{
        //         ans[i] = (color1.size()-counttrue) + maxi;
        //     }
        // }
        

        // return ans;

        auto adjA = buildList(edges1), adjB = buildList(edges2);
        int n = adjA.size(), m = adjB.size();
        vector<int> colorA(n, -1), colorB(m, -1);
        int evenA = 0, oddA = 0, evenB = 0, oddB = 0;
        colorA[0] = 0;
        dfsColor(adjA, 0, -1, colorA, evenA, oddA);
        colorB[0] = 0;
        dfsColor(adjB, 0, -1, colorB, evenB, oddB);
        int maxiB = max(evenB, oddB);
        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = (colorA[i] == 0 ? evenA : oddA) + maxiB;
        return res;
    }
};