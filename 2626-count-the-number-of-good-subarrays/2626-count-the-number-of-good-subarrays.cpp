class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        map<int,int>mp;

        int i=0;
        int j=0;
        long long int count = 0;
        long long int ans = 0;
        while(j<nums.size()){
            // cout<<mp[nums[j]]<<" ";
            count = count - ((1ll*mp[nums[j]] *( mp[nums[j]]-1))/2);
            // cout<<count<<" ";
            mp[nums[j]]++;
            // cout<<mp[nums[j]]<<" ";
            count = count + ((1ll*mp[nums[j]] * ( mp[nums[j]]-1))/2);
            // cout<<count<<endl;
            while(count>=k && i<=j){
                ans = ans + 1;
                ans = ans + (nums.size() - j - 1);

                count = count - ((1ll*mp[nums[i]] * ( mp[nums[i]]-1))/2);
                mp[nums[i]]--;
                count = count + ((1ll*mp[nums[i]] * ( mp[nums[i]]-1))/2);
                i++;
            }
            j++;
        }


        return ans;
    }
};