class Solution {
    
public:
    int longestCycle(vector<int>& edges) {

        vector<int>visited(edges.size(),0);

        int ans= -1;
        int loop  = 1;
        
        vector<int>time(edges.size());

        for(int i=0; i<edges.size(); i++){
            if(visited[i] != 0){
                continue;
            }
            int count = 0;
            int u = i;
            while(u != -1 && visited[u] == 0){
                visited[u] = loop;
                time[u] = count;
                count++;
                u = edges[u];
            }
            
            // cout<<u<<endl;

            if(u != -1 && visited[u] == loop){
                ans = max(ans, count-time[u]);
            }

            loop++;
        }

        if(ans == 0){
            return -1;
        }
        return ans;
    }
};