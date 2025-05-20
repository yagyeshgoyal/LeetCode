class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>>v(strs.size(),vector<int>(26,0));

        for(int i=0; i<strs.size(); i++){
            for(auto j : strs[i]){
                v[i][j-'a']++;
            }
        }

        vector<vector<string>>ans;
        vector<bool>visited(strs.size(), false);

        for(int i=0; i<strs.size(); i++){
            if(visited[i] == true){
                continue;
            }
            else{
                vector<string>temp;
                temp.push_back(strs[i]);
                vector<int>temp2 = v[i];

                for(int j = i+1; j<strs.size(); j++){
                    if(visited[j] == false && temp2 == v[j]){
                        visited[j] = true;
                        temp.push_back(strs[j]);
                    }
                }

                ans.push_back(temp);
            }
        }

        return ans;

    }
};