class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        stack<int>st;
        st.push(nums[nums.size()-1]);
        for(int i=nums.size()-2; i>0; i--){
            st.push(max(st.top(),nums[i]));
        }

        long long int ans = -1;

        for(int i=0; i<nums.size()-1; i++){
            if(st.top() > nums[i])
            ans = max<long long int>(ans,st.top()-nums[i]);
            st.pop();
        }

        return ans;
    }
};