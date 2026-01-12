class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>>ans;
        for(int i=0; i+3<nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j=i+1; j+2<nums.size(); j++){
                if(j>i+1 && nums[j] == nums[j-1]){
                    continue;
                }

                int k = j+1;
                int l = nums.size()-1;

                while(k<l){
                    long double p = (long double)nums[i] + (long double)nums[j] + (long double)nums[k] + (long double)nums[l];
                    
                    if(p==target ){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        while(k<l && nums[k] == nums[k-1]){
                            k++;
                        }
                        l--;
                        while(k<l && nums[l] == nums[l+1]){
                            l--;
                        }
                    }
                    else if(p<target){
                        k++;
                        while(k<l && nums[k] == nums[k-1]){
                            k++;
                        }
                    }
                    else{
                        l--;
                        while(k<l && nums[l] == nums[l+1]){
                            l--;
                        }
                    }
                }
            }
        }

        return ans;
    }
};