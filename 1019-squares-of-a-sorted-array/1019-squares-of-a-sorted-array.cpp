class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
        for(auto i : nums){
            ans.push_back(pow(i,2));
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};