class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        set<int>row;
        set<int>col;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(auto i : row){
            for(int j=0; j<m; j++){
                matrix[i][j] = 0;
            }
        }

        for(auto j : col){
            for(int i=0; i<n; i++){
                matrix[i][j] = 0;
            }
        }

        return ;
    }
};