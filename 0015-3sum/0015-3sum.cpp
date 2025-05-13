class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        map<int,int>mp;
        mp[nums[0]]++;
        for(int i=1; i+1<nums.size() ; i++){
            for(int j = i+1; j<nums.size(); j++){
                int a = 0-nums[i]-nums[j];
                int b = nums[i];
                int c = nums[j];
                if(mp.count(a) && st.find({a,b,c}) == st.end() && st.find({a,c,b}) == st.end() &&
                st.find({b,a,c}) == st.end() && st.find({b,c,a}) == st.end() && st.find({c,a,b}) == st.end() &&
                st.find({c,b,a}) == st.end() ){
                    st.insert({a,b,c});
                }
            }
            mp[nums[i]]++;
        }

        vector<vector<int>>ans;
        for(auto i : st){
            ans.push_back(i);
        }

        return ans;
    }
};