class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        
        vector<int>ans;
        
        for(int i=1; i<bounds.size(); i++){
            int diff = original[i]-original[i-1];
            
            int d = min(bounds[i][1]-diff,bounds[i-1][1]) - max(bounds[i][0]-diff,bounds[i-1][0]) + 1;
            bounds[i][0] = max(bounds[i][0]-diff,bounds[i-1][0]) + diff;
            bounds[i][1] = min(bounds[i][1]-diff,bounds[i-1][1]) + diff;
            
            ans.push_back(d);
        }
        
        sort(ans.begin(), ans.end());
        
        if(ans[0]<=0){
            return 0;
        }
        else{
            return ans[0];
        }
    }
};