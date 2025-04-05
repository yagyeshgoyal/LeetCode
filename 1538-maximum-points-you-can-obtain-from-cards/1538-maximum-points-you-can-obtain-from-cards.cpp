class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();
        vector<int>prefix(n+1,0);
        vector<int>sufix(n+1,0);

        for(int i=0; i<n; i++){
            prefix[i+1] = cardPoints[i] + prefix[i];
        }

        for(int i=n-1; i>=0; i--){
            sufix[i] = cardPoints[i] + sufix[i+1];
        }

        int ans = 0;

        for(int i=0; i<=min(k,n); i++){
            ans = max(ans, prefix[i] + sufix[n-max(0,k-i)]);
            // cout<<ans<<endl;
        }

        return ans;
    }
};