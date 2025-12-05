class Solution {
public:
    int findans(int i, int k, vector<int>&v, int val){
        if(i == v.size()){
            return -1;
        }

        if(v[i] >= k){
            v[i] = val;
            return 0;
        }

        int swap = findans(i+1,k,v,v[i]);
        if(swap == -1){
            return -1;
        }
        v[i] = val;
        return swap+1;
    }
    int minSwaps(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        vector<int>v(n,0);
        // map<int,set<int>>mp;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=n-1; j>=0; j--){
                if(grid[i][j] ==  0){
                    count++;
                }
                else{
                    break;
                }
            }
            // if(mp.count(count)){
            //     // cout<<i<<endl;
            //     return -1;
            // }
            // mp[count] = i;
            // mp[count].insert(i);
            v[i] = count;
        }
        // vector<int>v(n,0);
        // int k = n-1;
        // for(int i=0; i<n-1; i++){
        //     int p = k;
        //     if(!mp.count(p) && p<=(n-1)){
        //         p++;
        //     }
        //     if(!mp.count(p)) return -1;
        //     int pos = *(mp[p].begin());
        //     mp[p].erase(pos);
        //     if(mp[p].size() == 0){
        //         mp.erase(p);
        //     }
        //     cout<<pos<<" ";
        //     ans = ans + (pos - i) + v[pos];

        //     // cout<<ans<<endl;

        //     for(int j=i; j<pos; j++){
        //         v[j]++;
        //     }
        //     k--;
        // }

        // return ans;

        // int ans = 0;

        for(int i=0; i<n-1; i++){
            int swap = findans(i,n-1-i,v,-1);

            if(swap == -1){
                return -1;
            }

            ans = ans + swap;
        }

        return ans;
    }
};