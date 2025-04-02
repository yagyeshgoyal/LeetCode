class Solution {
public:
    vector<int>v;
    int i=0;
    int sum = 0;
    Solution(vector<int>& w) {
        v.push_back(w[0]);
        sum = w[0];
        for(int i=1;i<w.size();i++)
        {
            sum+=w[i];
            v.push_back(sum);
        }
    }
    
    int pickIndex() {
        int target = rand() % sum;
        for(int i=0;i<v.size();i++)
        {
            if(target < v[i])
            {
                return i;
            }
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */