class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int>prefix = nums;
        vector<int>sufix = nums;

        for(int i=1; i<nums.size(); i++){
            prefix[i] = max(prefix[i], prefix[i-1]);
        }

        for(int i=nums.size()-2; i>=0; i--){
            sufix[i] = max(sufix[i],sufix[i+1]);
        }

        long long int ans = 0;

        for(int i=1; i<nums.size()-1; i++){
            long long int temp = 1ll*(prefix[i-1] - nums[i])*sufix[i+1];
            ans = max(ans,temp);
        }

        return ans;
    }
};