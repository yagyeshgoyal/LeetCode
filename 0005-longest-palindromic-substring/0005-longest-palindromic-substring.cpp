class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1){
            return s;
        }
        string ans = "";

        for(int i=1; i<s.length(); i++){
            int low = i;
            int high = i;

            while(s[low] == s[high]){
                low--;
                high++;
                
                if(low == -1 || high == s.length()){
                    break;
                }
            }
            string palindrom = s.substr(low + 1, high - low - 1);
            if(palindrom.size() > ans.size()){
                ans  = palindrom;
            }

            low = i-1;
            high = i;

            while(s[low] == s[high]){
                low--;
                high++;
                
                if(low == -1 || high == s.length()){
                    break;
                }
            }
            palindrom = s.substr(low + 1, high - low - 1);
            if(palindrom.size() > ans.size()){
                ans  = palindrom;
            }

        }
        return ans;
    }
};