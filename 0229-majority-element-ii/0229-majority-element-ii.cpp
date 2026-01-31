class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ans1 = 0;
        int count1 = 0;
        int ans2 = 0;
        int count2 = 0;

        for(auto i : nums){
            if(count1 == 0 && count2 == 0){
                ans1 = i;
                count1++;
            }
            else if(count1 == 0 && count2 != 0 && ans2 != i){
                count1++;
                ans1 = i;
            }
            else if(count2 == 0 && ans1 != i){
                ans2 = i;
                count2++;
            }
            else if(ans1 == i){
                count1++;
            }
            else if(ans2 == i){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }

        vector<int>ans;
        count1=0;
        count2=0;

        for(auto i : nums){
            if(i == ans1) count1++;
            if(i==ans2) count2++;
        }

        // cout<<ans1<<" "<<ans2<<" "<<count1<<" "<<count2<<endl;

        if(count1>(nums.size())/3) ans.push_back(ans1);

        if(count2>(nums.size())/3 && ans1 != ans2) ans.push_back(ans2);

        return ans;
    }
};