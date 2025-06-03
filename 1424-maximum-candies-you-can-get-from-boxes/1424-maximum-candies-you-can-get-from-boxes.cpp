class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int>openboxes;
        map<int,int>closeboxes;
        map<int,int>boxeskey;

        for(auto i : initialBoxes){
            if(status[i] == 1){
                openboxes.push(i);
            }
            else{
                closeboxes[i]++;
            }
        }

        int ans = 0;
        while(!openboxes.empty()){
            int p = openboxes.front();
            openboxes.pop();

            ans = ans + candies[p];

            for(auto i : containedBoxes[p]){
                if(status[i] == 1){
                    openboxes.push(i);
                }
                else if(boxeskey[i]>0){
                    openboxes.push(i);
                    boxeskey[i]--;
                }
                else{
                    closeboxes[i]++;
                }
            }

            for(auto i : keys[p]){
                
                if(closeboxes[i]>0){
                    openboxes.push(i);
                    closeboxes[i]--;
                }
                else{
                    boxeskey[i]++;
                }
            }


        }

        return ans;

    }
};