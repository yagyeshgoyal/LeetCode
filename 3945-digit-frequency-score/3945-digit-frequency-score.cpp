class Solution {
public:
    int digitFrequencyScore(int n) {
        map<int,int>mp;

        while(n>0){
            int num = n%10;
            mp[num]++;
            n = n/10;
        }

        int ans = 0;

        for(auto i : mp){
            ans = ans + i.first*i.second;
        }

        return ans;
    }
};