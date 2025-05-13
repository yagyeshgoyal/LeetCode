class Solution {
public:
    int minMoves(vector<int>& nums) {
        int diff = nums[0];
        for(int i=1; i<nums.size(); i++){
            diff = min(diff, nums[i]);
        }

        int ans = 0;

        for(auto i : nums){
            ans = ans + (i - diff);
        }

        return ans;
    }
};