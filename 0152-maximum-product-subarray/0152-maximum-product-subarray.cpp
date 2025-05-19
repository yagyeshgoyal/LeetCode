class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int>v;
        v.push_back(-1);
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                v.push_back(i);
            }
        }
        v.push_back(nums.size());

        int ans = 0;
        for(int i=1; i<v.size(); i++){
            int prod = 1;
            int count = 0;
            int count2 = 0;
            for(int j=v[i-1]+1; j<v[i]; j++){
                prod = prod* nums[j];
                if(nums[j] == 1) count++;
                if(nums[j] == -1) count2++;
            }
            if((prod == 1 && (count2>0 || count>0)) || prod != 1){
                
                ans = max(ans,prod);
            }
            // cout<<ans<<endl;
            int k = prod;
            for(int j=v[i-1]+1; j<v[i]; j++){
                if(nums[j]<0){
                    k = k/nums[j];
                    break;
                }
                k = k/nums[j];
            }

            if((k == 1 && count>0) || k != 1){
                // cout<<"k"<<endl;
            ans = max(ans,k);
            }
            
        
            k = prod;
            for(int j=v[i]-1; j>v[i-1]; j--){
                if(nums[j]<0){
                    k = k/nums[j];
                    break;
                }
                k = k/nums[j];
            }

            if((k == 1 && count>0) || k != 1){
                // cout<<"k1"<<endl;
            ans = max(ans,k);
            }
        }

        return ans;

    }
};