class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        vector<set<int>>v(arr.size());
        set<int>st;
        for(int i=0; i<n; i++){
            st.insert(arr[i]);
            v[i].insert(arr[i]);
        }

        for(int i=0; i<n; i++){
            int p = arr[i];
            for(int j=i+1; j<n; j++){
                p = p | arr[j];
                if(v[j].find(p) != v[j].end()){
                    break;
                }
                else{
                    v[j].insert(p);
                    st.insert(p);
                }
            }
        }

        return st.size();
    }
};