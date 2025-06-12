class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        
        int ans  = INT_MIN;
        int n = nums.size();
        for(int i=0 ; i<n; i++){
//             int a = (i+1)%n;
//             int b = (i-1 + n)%n;
            
            ans = max(ans, abs(nums[i]-nums[(i+1)%n]));
        }
        
        return ans;
    }
};