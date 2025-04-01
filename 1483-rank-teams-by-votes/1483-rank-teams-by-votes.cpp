class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>>v(26);

        for(auto i : votes){
            for(int j =0; j<i.size(); j++){
                v[i[j]-'A'].push_back(j);
            }
        }

        priority_queue< pair<vector<int>,char>, vector<pair<vector<int>,char>>, greater<>>minheap;

        for(int i=0; i<26; i++){
            if(v[i].size() != 0){
                sort(v[i].begin(), v[i].end());
                minheap.push({v[i],char(i+'A')});
            }
        }

        string ans = "";
        while(!minheap.empty()){
            auto i = minheap.top();
            minheap.pop();
            ans.push_back(i.second);
        }

        return ans;
    }
};