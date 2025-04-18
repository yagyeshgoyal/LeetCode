class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }

        string temp = countAndSay(n-1);

        string ans = "";
        int count  = 1;

        for(int i=1; i<temp.size(); i++){
            if(temp[i] == temp[i-1]){
                count++;
            }
            else{
                ans = ans + to_string(count);
                ans.push_back(temp[i-1]);
                count = 1;
            }
        }

        ans = ans + to_string(count);
        ans.push_back(temp[temp.size()-1]);

        return ans;
    }
};