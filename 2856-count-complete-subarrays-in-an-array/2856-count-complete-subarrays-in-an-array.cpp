class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        map<int,int>mp;
        set<int>st;
        for(auto i : nums){
            st.insert(i);
        }

        int i=0;
        int j=0;
        int ans = 0;
        while(j<nums.size()){
            mp[nums[j]]++;
            st.erase(nums[j]);

            while(st.size() == 0 && i<=j){
                ans = ans + nums.size()-j;

                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    st.insert(nums[i]);
                }
                i++;
            }
            j++;
        }

        return ans;
    }
};