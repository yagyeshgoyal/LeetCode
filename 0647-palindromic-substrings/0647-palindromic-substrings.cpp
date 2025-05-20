class Solution {
public:
    int countSubstrings(string s) {
        vector<int>v;
        vector<char>vs;
        char c = s[0];
        int count =1;

        for(int i=1; i<s.length(); i++){
            if(c == s[i]){
                count++;
            }
            else{
                vs.push_back(c);
                v.push_back(count);
                c = s[i];
                count = 1;
            }
        }
        vs.push_back(c);
        v.push_back(count);

        int ans = 0;
        for(int i=0; i<v.size(); i++){
            ans = ans + (v[i]*(v[i]+1))/2;
        }

        for(int i=1; i<v.size()-1; i++){
            int l = i-1;
            int r = i+1;

            while(l>=0 && r<v.size() && vs[l] == vs[r] ){
                ans = ans + min(v[l],v[r]);

                if(v[l] != v[r]){
                    break;
                }
                l--;
                r++;
            }
        }

        return ans;
    }
};