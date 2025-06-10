class Solution {
public:
    int maxDifference(string s) {
        vector<int>v(26,0);
        for(auto i : s){
            v[i-'a']++;
        }
        vector<int>even;
        vector<int>odd;

        for(int i = 0 ; i<26; i++){
            if(v[i]%2 == 1){
                odd.push_back(v[i]);
            }
            else if(v[i] != 0 ){
                even.push_back(v[i]);
            }
        }

        sort(even.begin(), even.end());
        sort(odd.begin(),odd.end());

        return odd[odd.size()-1]-even[0];
    }
};