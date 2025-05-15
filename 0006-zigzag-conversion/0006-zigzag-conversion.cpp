class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        string ans = "";
        for(int i=0; i<numRows; i++){
            if(i == 0 || i == numRows-1){
                int temp1 = (numRows-1)*2;
                int ind = i;
                while(ind<s.length()){
                    ans.push_back(s[ind]);
                    ind = ind + temp1;
                }
            }
            else{
                int temp1 = (numRows-i-1)*2;
                int temp2 = i*2;
                int ind = i;
                
                while(ind<s.length()){
                    // cout<<temp1<<endl;
                    ans.push_back(s[ind]);
                    ind = ind + temp1;

                    if(ind<s.length()){
                        ans.push_back(s[ind]);
                        ind = ind + temp2;
                    }
                }
            }
        }

        return ans;
    }
};