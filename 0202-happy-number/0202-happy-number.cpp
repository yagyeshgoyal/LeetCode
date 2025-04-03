class Solution {
public:
    bool isHappy(int n) {
        
        while(n>9){
            int p = n;
            n = 0;
            while(p>0){
                n = n + (p%10)*(p%10);
                p = p /10;
            }
        }

        if(n==1 || n==7){
            return true;
        }

        return false;
    }
};