class Solution {
    private:
    void findXor(vector<int>&nums, int index, int currXor, int &result){
        if(index == nums.size()){
            result = result + currXor;
            return ;
        }

        //includeing
        findXor(nums,index + 1, currXor^nums[index] , result);

        //excluding
        findXor(nums, index+1, currXor, result);

        return;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int result = 0;
        // for(int i=0; i<nums.size(); i++){
        //     findXor(nums,i+1,nums[i],result);
        //     // result = result + nums[i];
        // }
        findXor(nums,0,0,result);

        return result ;
    }
};