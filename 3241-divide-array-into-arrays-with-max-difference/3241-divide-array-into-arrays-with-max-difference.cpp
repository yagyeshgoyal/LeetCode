class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<vector<int>>ans;
        bool flage = true;
        for(int i=0; i<nums.size(); i= i+3){
            if(nums[i+2]-nums[i] > k){
                flage = false;
            }
        }

        if(flage){
            for(int i = 0; i<nums.size(); i= i+3){
                vector<int>temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[i+1]);
                temp.push_back(nums[i+2]);

                ans.push_back(temp);
            }
        }

        return ans;
    }
};