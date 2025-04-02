class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string p;
        string q;

        if(str1.length() <= str2.length()){
            p = str2;
            q = str1;
        }
        else{
            p = str1;
            q = str2;
        }

        vector<string>v;
        string temp = "";
        for(int i=0; i<q.length(); i++){
            temp.push_back(q[i]);
            if(q.length()%temp.length() == 0){
                v.push_back(temp);
            }
        }

        string ans = "";
        temp = "";
        string temp2 = "";
        if(p == str1){
            for(int i=v.size()-1; i>=0; i--){
                if(p.length()%v[i].length() == 0){
                    temp = "";
                    temp2 = "";
                    for(int j=0; j<p.length()/v[i].length(); j++){
                        temp = temp + v[i];
                    }
                    for(int j=0; j<str2.length()/v[i].length(); j++){
                        temp2 = temp2 + v[i];
                    }

                    if(temp == p && temp2 == str2){
                        ans = v[i];
                        break;
                    }
                }
            }
        }
        else{
            for(int i=v.size()-1; i>=0; i--){
                if(p.length()%v[i].length() == 0){
                    temp = "";
                    temp2 = "";
                    for(int j=0; j<p.length()/v[i].length(); j++){
                        temp = temp + v[i];
                    }
                    for(int j=0; j<str1.length()/v[i].length(); j++){
                        temp2 = temp2 + v[i];
                    }

                    if(temp == p && temp2 == str1){
                        ans = v[i];
                        break;
                    }
                }
            }
        }

        return ans;
    }
};