class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int i = low;
        int ans = 0;
        while(i<=high){
            if(i>10 && i<100){
                if(i%10 == i/10){
                    ans++;
                }
            }
            else if(i>=1000 && i<10000){
                if(i/1000 + (i%1000)/100 == (i%100)/10 + i%10){
                    ans++;
                }
            }

            i++;
        }
        return ans;
    }
};