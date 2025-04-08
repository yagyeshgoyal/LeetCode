class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int>mp;
        set<int>st;
        
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
            st.insert(nums[i]);
        }
        
        int i=0;
        int ans = 0;
        while(nums.size()-i != st.size()){
            // cout<<i<<" "<<nums.size()-i<<" "<<st.size()<<endl;
            ans++;
            for(int j=i; j<min<int>(i+3,nums.size()); j++){
                // cout<<j<<" ";
                if(mp[nums[j]] == 1){
                    mp[nums[j]]--;
                    st.erase(nums[j]);
                }
                else{
                    mp[nums[j]]--;
                }
                
            }
            // cout<<endl;
            
            i=min<int>(i+3,nums.size());
            
            if(i == nums.size()){
                break;
            }
        }
        
        return ans;
        
        
    }
};