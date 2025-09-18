class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if(nums.size()%k != 0){
            return false;
        }

        map<int,int>mp;
        for(auto i : nums){
            mp[i]++;
        }

        priority_queue<int>q;
        for(auto i : mp){
            q.push(i.second);
        }

        while(!q.empty()){
            if(q.size()<k){
                return false;
            }
            vector<int>v;
            for(int i=0; i<k; i++){
                if(q.top()>1)
                v.push_back(q.top()-1);
                q.pop();
            }

            for(auto i : v){
                q.push(i);
            }
        }

        return true;
    }
};