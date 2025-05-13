class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>mp;
        map<char,int>freq;

        for(int i=s.size()-1; i>=0; i--){
            mp[s[i]] = i;
            freq[s[i]]++;
        }

        int ans = -1;
        for(auto i : mp){
            if(freq[i.first] == 1){
                if(ans == -1){
                    ans = i.second;
                }
                else
                ans = min(ans,i.second);
            }
        }

        return ans;
    }
};