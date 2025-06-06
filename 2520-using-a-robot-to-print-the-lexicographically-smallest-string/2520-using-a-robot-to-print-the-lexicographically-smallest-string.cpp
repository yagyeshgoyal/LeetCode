class Solution {
public:
    string robotWithString(string s) {
        vector<int>v(26,0);
        for(auto i : s){
            v[i-'a']++;
        }

        stack<char>st;
        string ans = "";
        vector<int>v2(26,0);
        vector<int>v3(26,0);

        int j = 0;
        while(v2[j] == v[j]){
            j++;
        }

        for(int i=0; i<s.length(); i++){
            if(j != s[i]-'a'){
                st.push(s[i]);
                v2[s[i]-'a']++;
                v3[s[i]-'a']++;
            }
            else{
                ans.push_back(s[i]);
                v3[s[i]-'a']++;

                if(v3[j] == v[j]){
                    j++;
                    while(true){
                        if(j==26){
                            break;
                        }
                        if(st.size()>0 && st.top()-'a' == j){
                            while(st.size()>0 && st.top()-'a'<=j){
                                ans.push_back(st.top());
                                v2[st.top()-'a']--;
                                st.pop();
                            }
                        }
                        else if(v3[j]<v[j]){
                            break;
                        }
                        else if(v3[j] == v[j] && st.size()>0 && st.top()-'a' == j){
                            while(st.size()>0 && st.top()-'a'<=j){
                                ans.push_back(st.top());
                                v2[st.top()-'a']--;
                                st.pop();
                            }
                            j++;
                        }
                        else{
                            j++;
                        }
                    }
                }


            }
        }

        return ans;
    }
};