class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<char>c;
        vector<int>freq;
        char ch = s[0];
        int count = 1;
        for(int i=1; i<s.size();i++){
            if(s[i] == ch){
                count++;
            }
            else{
                c.push_back(ch);
                freq.push_back(count);
                ch = s[i];
                count = 1;
            }
        }

        c.push_back(ch);
        freq.push_back(count);

        // for(int i = 0 ; i<c.size(); i++){
        //     cout<<c[i]<<" "<<freq[i]<<endl;
        // }

        int ans = 0;

        for(auto ss : words){
             ch = ss[0];
             count = 1;
             bool flage =true;
             int idx = 0;

             
            for(int i=1; i<ss.length(); i++){
                if(ch == ss[i]){
                    count++;
                }
                else{
                    if(idx < c.size() && ch == c[idx] && (count == freq[idx] || (freq[idx]>=3 && count<=freq[idx]))){
                        ch = ss[i];
                        count = 1;
                        idx++;
                    }
                    else{
                        // cout<<ch<<" "<<ss<<endl;
                        flage = false;
                        break;
                    }
                }

            }

            if(idx == c.size()-1 && ch == c[idx] &&  (count == freq[idx] || (freq[idx]>=3 && count<=freq[idx]))){
                // ch = ss[i];
                count = 1;
            }
            else{
                // cout<<ch<<" "<<ss<<endl;
                flage = false;
            }

            if(flage){
                ans++;
            }

        }

        return ans;
    }
};