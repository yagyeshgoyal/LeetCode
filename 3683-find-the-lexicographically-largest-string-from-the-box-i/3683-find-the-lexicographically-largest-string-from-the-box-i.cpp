class Solution {
public:
    string answerString(string word, int numFriends) {
        
        if(numFriends == 1){
            return word;
        }
        
        char ch = word[0];
        for(int i=1; i<word.length(); i++){
            if(word[i]>ch){
                ch = word[i];
            }
        }
        
        vector<string>v;
        int l = word.length()-1;
        
        for(int i=0; i<word.length(); i++){
            if(ch == word[i]){
                int p = numFriends-i-1;
                // cout<<i<<" "<<p<<" "<<l-p<<endl;
                p = max(0,p);
                // string temp = word.substr(i,l-p);
                string temp = "";
                for(int j=i; j<=l-p; j++){
                    temp.push_back(word[j]);
                }
                // cout<<temp<<endl;
                v.push_back(temp);
            }
        }
        
        sort(v.begin(),v.end());
        
        return v[v.size()-1];
    }
};