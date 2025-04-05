class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>>mp;

        for(int i=0; i<s.length(); i++){
            mp[s[i]].push_back(i);
        }

        
        int ans = 0;

        for(int j=0; j<words.size(); j++){
            int i=-1;
            bool flage = true;
            for(auto k : words[j]){

                if(mp.count(k)){
                    auto it = upper_bound(mp[k].begin(), mp[k].end(),i);
                    if(it != mp[k].end()){
                        i = *it;
                    }
                    else{
                        flage = false;
                        break;
                    }
                }
                else{
                    flage = false;
                    break;
                }
            }

            if(flage){
                ans++;
            }
        }

        return ans;
    }
};