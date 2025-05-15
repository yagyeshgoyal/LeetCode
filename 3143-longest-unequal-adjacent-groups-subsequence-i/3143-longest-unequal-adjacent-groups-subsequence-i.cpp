class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans;
        int count= 0;

        ans.push_back(words[0]);
        count = groups[0];

        for(int i=1; i<words.size(); i++){
            if(groups[i] != count){
                ans.push_back(words[i]);
                count = groups[i];
            }
        }

        return ans;
    }
};