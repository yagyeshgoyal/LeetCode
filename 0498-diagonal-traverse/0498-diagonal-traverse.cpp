class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;

        int n = mat.size();
        int m = mat[0].size();

        for(int i=0; i<n; i++){
            int p = i;
            int j = 0;
            vector<int>temp;
            while(p>=0 && j<m){
                temp.push_back(mat[p][j]);
                p--;
                j++;
            }

            if(i%2 == 1){
                reverse(temp.begin(), temp.end());
            }

            for(auto k : temp){
                ans.push_back(k);
            }
        }

        for(int j=1; j<m; j++){
            int i=n-1;
            int p = j;
            vector<int>temp;

            while(i>=0 && p<m){
                temp.push_back(mat[i][p]);
                i--;
                p++;
            }

            if(n%2 == j%2){
                reverse(temp.begin(), temp.end());
            }

            for(auto k : temp){
                ans.push_back(k);
            }
        }

        return ans;
    }
};