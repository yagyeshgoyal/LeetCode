class Solution {
    int setbit(int i){
        int ans = 0;

        while(i>0){
            if(i&1){
                ans++;
            }
             i = i/2;
        }
        return ans;
    }
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        set<int>st;
        for(auto i : nums){
            st.insert(i);
        }

        vector<int>v;
        for(auto i : st){
            int cnt = setbit(i);
            v.push_back(cnt);
        }

        sort(v.begin(), v.end());

        int l = 0;
        int r = v.size()-1;
        long long int ans = 0;

        while(l<v.size() && r>=0){
            if(v[l]+v[r]<k){
                l++;
            }
            else{
                ans = ans + (v.size()-l);
                r--;

            }
        }

        return ans;
    }
};