class Solution {
public:
    int minOperations(vector<int>& nums) {
        int lastnum = nums[0];
        int ans = 0;

        for(int i=1; i<nums.size(); i++){
            if(lastnum>=nums[i]){
                ans = ans + (lastnum - nums[i] + 1);
                lastnum++;
            }
            else{
                lastnum = nums[i];
            }
        }

        return ans;
    }
};