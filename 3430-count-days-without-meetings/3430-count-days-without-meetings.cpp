class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int last = 1;
        int ans = meetings[0][0]-1;
        last = meetings[0][1];

        for(int i=1; i<meetings.size(); i++){
            if(meetings[i][0] <last){
                last = max(last,meetings[i][1]);
            }
            else{
                ans = ans + meetings[i][0] - last-1;
                if(meetings[i][0] == last){
                    ans++;
                }
                last = meetings[i][1];
            }
        }

        if(last != days){
            ans = ans + days - last;
        }

        return ans;
    }
};