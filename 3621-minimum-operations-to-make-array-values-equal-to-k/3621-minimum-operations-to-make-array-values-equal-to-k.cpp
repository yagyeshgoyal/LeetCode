class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        set<int>st;
        for(auto i : nums){
            st.insert(i);
        }
        
        if(*st.begin()<k){
            return -1;
        }
        else if(*st.begin() > k){
            return st.size();
        }
        else {
            return st.size()-1;
        }
        
        return -1;
    }
};