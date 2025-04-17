class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>prefix(nums.size()+1,0);
        for(int i=0; i<nums.size(); i++){
            prefix[i+1] = prefix[i] + nums[i];
        }

        vector<int>sufix(nums.size()+1,0);
        for(int i=nums.size()-1; i>=0; i--){
            sufix[i] = sufix[i+1] + nums[i];
        }
        int ans = -1;
        for(int i=1; i<= nums.size(); i++){
            if(prefix[i-1] == sufix[i]){
                ans = i-1;
                break;
            }
        }

        return ans;
    }
};