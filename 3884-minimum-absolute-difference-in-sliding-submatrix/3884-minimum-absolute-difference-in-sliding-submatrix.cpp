class Solution {
    void findans(int top , int bottom, int left, int right, set<int>&st,
         map<int,int>&mp,vector<int>&temp,vector<vector<int>>& grid  ){
        if(right == grid[0].size()) return ;

        for(int i=top; i<=bottom; i++){
            st.insert(grid[i][right]);
            mp[grid[i][right]]++;
        } 

        int mini = INT_MAX;
        auto it = st.begin();
        
        int k = *it;
        it++;
        // cout<<st.size()<<endl;
        while(it != st.end()){
            // cout<<mini<<endl;
            

            mini = min(mini, *it-k);
            k = *it;
            it++;
        }
        if(st.size() == 1){
            mini = 0;
        }
        temp.push_back(mini);

        for(int i=top; i<=bottom; i++){
            st.insert(grid[i][right]);
            mp[grid[i][left]]--;

            if(mp[grid[i][left]] == 0){
                st.erase(grid[i][left]);
            }
        }

        findans(top,bottom,left+1,right+1,st,mp,temp,grid);

        return ;
     }
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>ans;

        for(int i=0; i+k-1<n; i++){
            vector<int>temp;
            set<int>st;
            map<int,int>mp;
            for(int j = i; j<= i+k-1; j++){
                for(int p=0; p<=k-2; p++){
                    st.insert(grid[j][p]);
                    mp[grid[j][p]]++;
                }
            }
            findans(i,i+k-1,0,k-1,st,mp,temp,grid);
            ans.push_back(temp);
        }

        return ans;
    }
};