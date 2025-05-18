class Solution {
public:
    int minSwaps(vector<int>& nums) {
        map<int,int>mp;
        vector<pair<int,int>>pq;
        
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]] = i;
            int k = nums[i];
            int sum = 0;
            while(nums[i]>0){
                sum = sum+ nums[i]%10;
                nums[i] = nums[i]/10;
            }
            nums[i] = k;
            pq.push_back({sum,k});
        }
        sort(pq.begin(), pq.end());
        
        vector<int>v;
        for(auto i : pq){
            v.push_back(i.second);
        }
        
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == v[i]){
                continue;
            }
            else{
                int k = mp[v[i]];
                
                swap(mp[v[i]], mp[nums[i]]);
                swap(nums[i],nums[k]);
                ans++;
            }
        }
        
        return ans;
        
        
    }
};