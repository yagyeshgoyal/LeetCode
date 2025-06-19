class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        map<int,int>mp;
        multiset<int>st;

        for(auto i : nums){
            mp[i]++;
            st.insert(i);
        }

        int ans = 0;
        while(st.size()>0){
            ans++;
            int a = *st.begin();
            vector<int>v;
            for(auto i : st){
                if(i-a>k){
                    break;
                }
                else{
                    mp[i]--;
                    if(mp[i] == 0){
                        v.push_back(i);
                    }
                }
            }
            for(auto i : v){
                st.erase(i);
            }

        }

        return ans;
    }
};