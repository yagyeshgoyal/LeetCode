class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        bool flage = false;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '['){
                flage = true;
                continue;
            }
            else if(s[i] == ']'){
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();

                while(s2[0]-'0' > 9){
                    s1 = s2 + s1;
                    s2 = st.top();
                    st.pop();
                }

                int a = stoi(s2);
                string temp = "";
                for(int i=0; i<a; i++){
                    temp = temp + s1;
                }
                string s3;
                if(st.size()>0){
                    s3 = st.top();
                    st.pop();
                }
                else{
                    s3 = "";
                }
                
                s3 = s3 + temp;
                st.push(s3);
            }
            else if(s[i]-'0' > 0 && s[i]-'0'<=9){
                if(flage){
                    st.push("");
                    flage = false;
                }
                string temp = "";

                while(s[i] != '['){
                    temp.push_back(s[i]);
                    i++;
                }
                st.push(temp);
                i--;
            }
            else{
                flage = false;
                string temp = "";

                while(s[i] != '[' && s[i] != ']' && s[i]-'0' >9){
                    temp.push_back(s[i]);
                    i++;
                }
                st.push(temp);
                i--;
            }
        }

        string ans = "";
        while(st.size()>0){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};