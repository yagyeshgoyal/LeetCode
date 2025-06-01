class Solution {
bool findans(int i, vector<int>&nums, long double mul , long long &target,
            map<int,map<long double,bool>>&dp){
    if(i == nums.size()) return false;

    if(mul > target){return false;}

    if(mul == target) return true;

    if(dp.count(i) && dp[i].count(mul)){
        return dp[i][mul];
    }
    
    bool ans1 = findans(i+1, nums, (mul== 0)?nums[i]: mul*nums[i], target,dp);
    bool ans2 = findans(i+1, nums, mul , target,dp);

    return dp[i][mul] = ans1 | ans2;
}
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        map<int,map<long double,bool>>dp;
        bool ans = findans(0,nums,0,target,dp);
        long double mul = 1;
        for(auto i : nums){
            mul = 1ll*mul*i;
        }
        if(ans && mul/target == target){
            return true;
        }
        return false;
    }
};