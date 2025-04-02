class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());

        int ans = INT_MAX;
        int n = timePoints.size();
        for(int i=0; i<n-1; i++){
            int hour = ((timePoints[i+1][0]-'0')-(timePoints[i][0]-'0'))*10 + ((timePoints[i+1][1]-'0')-(timePoints[i][1]-'0'));
            int mint = ((timePoints[i+1][3]-'0')-(timePoints[i][3]-'0'))*10 + ((timePoints[i+1][4]-'0')-(timePoints[i][4]-'0'));

            ans = min(ans, hour*60 + mint);
        }

        int hour = ((2)-(timePoints[n-1][0]-'0'))*10 + ((4)-(timePoints[n-1][1]-'0'));
            int mint = ((0)-(timePoints[n-1][3]-'0'))*10 + ((0)-(timePoints[n-1][4]-'0'));

         hour = hour +  ((timePoints[0][0]-'0')-(0))*10 + ((timePoints[0][1]-'0')-(0));
         mint = mint +  ((timePoints[0][3]-'0')-(0))*10 + ((timePoints[0][4]-'0')-(0));

         ans = min(ans, hour*60 + mint);

         return ans;
    }
};