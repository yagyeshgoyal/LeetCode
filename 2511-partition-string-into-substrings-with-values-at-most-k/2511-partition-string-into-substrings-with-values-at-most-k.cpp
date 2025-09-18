class Solution {
public:
    int minimumPartition(string s, int k) {
        string num = to_string(k);
        if(k/10 >0){
            string temp = "";
            int count = 0;
            for(int i=0; i<s.length(); i++){
                temp.push_back(s[i]);
                if(temp.size() >9 || stoi(temp) > k){
                    count++;
                    temp = "";
                    temp.push_back(s[i]);
                }
            }
            count++;
            return count;
        }
        else{
            for(auto i : s){
                string p = "";
                p.push_back(i);
                if(p>num){
                    return -1;
                }
            }

            return s.length();
        }

        return -1;
    }
};