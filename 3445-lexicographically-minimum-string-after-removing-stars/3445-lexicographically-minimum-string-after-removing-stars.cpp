class Solution {
public:
    string clearStars(string s) {
        map<int,stack<int>>mp;
        set<int>st;
        
        for(int i=0; i<s.length(); i++){
            if(s[i] != '*'){
                mp[s[i]-'a'].push(i);
                st.insert(s[i]-'a');
            }
            else{
                s[i] = '?';
                // for(int i=0; i<26; i++){
                //     if(mp[i].size()>0){
                //         int k = mp[i].top();
                //         mp[i].pop();
                //         s[k] = '?';
                //         break;
                //     }
                // }
                auto it = st.begin();
                int k = mp[*it].top();
                mp[*it].pop();
                s[k] = '?';
                if(mp[*it].size()<=0){st.erase(*it);}
            }
        }
        
        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] != '?'){
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};