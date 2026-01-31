class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int count = 0;

        for(auto i : nums){
            if(count == 0){
                count++;
                ans = i;
            }
            else if(ans == i){
                count++;
            }
            else{
                count--;
            }
        }

        return ans;
    }
};