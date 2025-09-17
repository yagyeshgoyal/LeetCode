class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>ans(n,vector<int>(m));
        vector<vector<int>>a(n,vector<int>(m));
        vector<vector<int>>b(n,vector<int>(m));
        long long int p = 1;
        int mod  = 12345;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                a[i][j] = p;
                p = (p*grid[i][j])%mod;

            }
        }

        p = 1;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                b[i][j] = p;
                p = (p*grid[i][j])%mod;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0 ; j<m; j++){
                ans[i][j] = (a[i][j] * b[i][j])%mod;
            }
        }

        return ans;
    }
};