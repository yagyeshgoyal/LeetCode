class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(), answers.end());
        int i=0;
        int j=1;

        int ans = 0;
        while(j<answers.size()){
            if(answers[j]!= answers[j-1]){
                int dis = j-i;
                int div = answers[i]+1;
                if(dis%div == 0){
                    ans = ans + dis;
                }
                else{
                    ans = ans + (dis/div)*div  + div;
                }
                i = j;
            }
            j++;
        }
        int dis = j-i;
        int div = answers[i]+1;
        if(dis%div == 0){
            ans = ans + dis;
        }
        else{
            ans = ans + (dis/div)*div  + div;
        }

        return ans;

    }
};