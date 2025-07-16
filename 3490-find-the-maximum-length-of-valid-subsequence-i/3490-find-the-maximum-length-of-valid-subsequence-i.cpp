class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int counteven = 0;
        int countodd = 0;

        for(auto i : nums){
            if(i%2 == 0){
                counteven++;
            }
            else{
                countodd++;
            }
        }

        int top = nums[0];
        int count = 1;
        for(int i=1; i<nums.size(); i++){
            if(top%2 != nums[i]%2){
                count++;
                top = nums[i];
            }
        }

        int ans = max(count,max(counteven,countodd));

        return ans;
    }
};