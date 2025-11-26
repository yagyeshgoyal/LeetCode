class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        map<long long int,vector<long long int>>mp;
        set<long long int>st;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>>pq;

        for(int i=0; i<servers.size(); i++){
            pq.push({servers[i],i});
        }

        vector<int>ans(tasks.size());
        int k = 0;
        for(int i=0; i<tasks.size(); i++){
            for(auto j : mp[k]){
                pq.push({servers[j],j});
            }
            st.erase(k);
            mp.erase(k);
            if(pq.size() == 0){
                k = *st.begin();
                for(auto j : mp[k]){
                    pq.push({servers[j],j});
                }
                st.erase(k);
                mp.erase(k);
            }

            auto front = pq.top();
            pq.pop();
            // cout<<front.second<<" "<<pq.size()<<endl;
            ans[i] = front.second;
            mp[k+tasks[i]*1ll].push_back(front.second);
            st.insert(k+tasks[i]*1ll);
            if(i==k)
            k++;
        }

        return ans;
    }
};