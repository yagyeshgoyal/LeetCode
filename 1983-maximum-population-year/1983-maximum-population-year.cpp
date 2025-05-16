class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>diff(101,0);

        for(auto &vec:logs){
            int l=vec[0]-1950;
            int r=vec[1]-1950;

            diff[l]++;
            diff[r]--;
        }
        int ans=1950,maxPop=diff[0];
        for(int i=1;i<101;i++){
            diff[i]+=diff[i-1];
            if(diff[i]>maxPop){
                maxPop=diff[i];
                ans=1950+i;
            }
        }
        return ans;
    }
};