class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        vector<int>prefix = nums;
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i] + prefix[i-1];
        }

        map<int,int>mp;
        mp[0]++;
        for(int i=0; i<n; i++){
            if(mp.count(prefix[i]-k)){
                ans += mp[prefix[i]-k];
            }

            mp[prefix[i]]++;
        }

        return ans;

    }
};