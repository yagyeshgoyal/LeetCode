class Solution {
    int findans(int i , int currsum , int reqsum, vector<int>&nums, vector<vector<int>>&dp){
        if(currsum == reqsum){
            return 1;
        }
        
        if(currsum> reqsum || i >= nums.size()){
            return 0;
        }

        if(dp[i][currsum] != -1){
            return dp[i][currsum];
        }

        int ans1 = findans(i+1,currsum+nums[i],reqsum,nums,dp);
        int ans2 = findans(i+1,currsum,reqsum,nums,dp);

        if(ans1 == 1 || ans2 == 1){
            return dp[i][currsum] = 1;
        }

        return dp[i][currsum] = 0;
    }
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(auto i : nums){
            total += i;
        }

        if(total & 1){
            return false;
        }

        int sum = total/2;

        vector<vector<int>>dp(nums.size()+1, vector<int>(sum+1,-1));
        
        int ans = findans(0,0,sum,nums,dp);

        if(ans){
            return true;
        }
        return false;
    }
};