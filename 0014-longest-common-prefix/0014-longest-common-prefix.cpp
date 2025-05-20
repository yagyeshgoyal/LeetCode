class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];

        for(int i=1; i<strs.size(); i++){
            int j;
            int k;
            for(j=0,k=0; j<strs[i].length()&& k<ans.size(); j++,k++){
                if(strs[i][j] != ans[k]){
                    break;
                }
            }

            if(k != ans.size()){
                ans = ans.substr(0,j);
            }
            
        }
        return ans;
    }
};