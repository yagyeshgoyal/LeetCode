class Solution {
public:
    string addStrings(string num1, string num2) {
        while(num1.length() != num2.length()){
            if(num1.length() < num2.length()){
                num1 = "0" + num1;
            }
            else if(num1.length() > num2.length()){
                num2 = "0" + num2;
            }
        }

        string ans = "";
        int carry = 0;
        for(int i= num1.length()-1; i>=0; i--){
            int a = num1[i]-'0';
            int b = num2[i] - '0';

            int c = a+b + carry;;
            if(c>9){
                carry = 1;
            }
            else{
                carry = 0;
            }

            int d = c%10;
            ans.push_back(d+'0');
        }

        if(carry == 1){
            ans.push_back('1');
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};