class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        int count = 0;
        for(auto i : words){
            for(auto j : i){
                if(j == x){
                    ans.push_back(count);
                    break;
                }
            }
            count++;
        }

        return ans;
    }
};