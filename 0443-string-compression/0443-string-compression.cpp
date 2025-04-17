class Solution {
public:
    int compress(vector<char>& chars) {
        vector<int>v(128,0);

        string s = "";
        s.push_back(chars[0]);
        v[chars[0]-'!']++;
        for(int i=1; i<chars.size(); i++){
            if(chars[i] == chars[i-1]){
                v[chars[i]-'!']++;
            }
            else{
                if(v[chars[i-1]-'!'] != 1){
                    s = s + to_string(v[chars[i-1]-'!'] );
                }
                v[chars[i-1]-'!'] = 0;
                s.push_back(chars[i]);
                v[chars[i]-'!']++;
            }
        }

        if(v[chars[chars.size()-1]-'!'] != 1){
            s = s + to_string(v[chars[chars.size()-1]-'!'] );
        }
        
        cout<<s<<endl;
        cout<<s.size()<<endl;
        chars.resize(s.size());
        for(int i = 0; i<s.size(); i++){
            chars[i] = s[i];
        }
        return s.size();

    }
};