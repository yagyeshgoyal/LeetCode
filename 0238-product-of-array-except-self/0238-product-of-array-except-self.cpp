class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long int product = 1;
        int zero = 0;

        for(auto i : nums){
            if(i == 0){
                zero++;
            }
            else{
                product = product*i;
            }
        }

        vector<int>ans;

        for(int i=0; i<nums.size(); i++){
            if(zero>1){
                ans.push_back(0);
            }
            else if(nums[i] == 0){
                ans.push_back(product);
            }
            else if(nums[i] != 0 && zero == 1){
                ans.push_back(0);
            }
            else{
                ans.push_back(product/nums[i]);
            }
        }

        return ans;
    }
};