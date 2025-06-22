class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        string temp  = "";
        for(int i=0; i<s.length(); i++){
            temp.push_back(s[i]);

            if(temp.size() == k){
                ans.push_back(temp);
                temp = "";
            }
        }

        if(temp.size()>0){
            for(int i= temp.size()+1; i<=k; i++){
                temp.push_back(fill);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};