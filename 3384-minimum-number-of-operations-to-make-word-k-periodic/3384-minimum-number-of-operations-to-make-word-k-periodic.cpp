class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        map<string,int>mp;
        // int p =0;
        for(int i=0; i<word.length(); i = i + k){
            string temp = word.substr(i,k);
            mp[temp]++;
        }
        int ans = 0;
        int maxi = 0;
        for(auto i : mp){
            if(i.second>maxi){
                ans += maxi;
                maxi = i.second;
            }
            else{
                ans = ans + i.second;
            }
        }

        return ans;
    }
};