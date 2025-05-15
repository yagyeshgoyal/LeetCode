class Solution {
public:
    int rob(vector<int>& nums) {
        int a,b,c,d,e,f;
        a = 0 ;
        b= 0;
        c = nums[nums.size()-1];
        d  = 0;

        for(int i = nums.size()-2; i>=0; i--){
            e = nums[i] + max(b,d);
            f = max(a,c);
            a = c;
            b = d;
            c = e;
            d = f; 
        }

        return max(c,d);
    }
};