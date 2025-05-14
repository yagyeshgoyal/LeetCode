class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto i : nums){
            mp[i]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> >pq;

        for(auto i : mp){
            if(pq.size() == k){
                if(pq.top().first< i.second){
                    pq.pop();
                    pq.push({i.second,i.first});
                }
            }
            else{
                pq.push({i.second, i.first});
            }
        }

        vector<int>ans;
        while(!pq.empty()){
            auto i = pq.top();
            pq.pop();
            ans.push_back(i.second);
        }

        return ans;
    }
};