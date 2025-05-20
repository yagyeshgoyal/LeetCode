class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";

        for(int i=0; i<s.length(); i++){
            if(s[i]>='A' && s[i]<='Z'){
                t.push_back((s[i]-'A')+'a');
            }
            else if(s[i]>='a' && s[i]<='z'){
                t.push_back(s[i]);
            }
            else if(s[i]>='0' && s[i]<='9'){
                t.push_back(s[i]);
            }
            
        }

        int l = 0;
        int r = t.length()-1;

        while(l<r){
            if(t[l] != t[r]){
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};