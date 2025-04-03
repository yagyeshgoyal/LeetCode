class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;

        string temp = "";
        vector<pair<int,pair<int,int>>>v;
        
        int a = 0;
        int sum = words[0].length();

        for(int i=1; i<words.size(); i++){
            if(sum+ 1 + words[i].length() <= maxWidth){
                sum = sum + 1 + words[i].length();
            }
            else{
                v.push_back({sum,{a,i-1}});
                a = i;
                sum = words[i].length();
            }
        }

        v.push_back({sum,{a,words.size()-1}});

        for(int i=0; i<v.size()-1; i++){
            int len = v[i].first;
            int l = v[i].second.first;
            int r = v[i].second.second;
            int diff = r-l;
            if(diff != 0){
                int k = (maxWidth-len)%diff;

                temp = words[l];
                for(int j=l+1; j<=r; j++){
                    temp = temp + " ";
                    for(int r = 0; r<(maxWidth-len)/diff; r++){
                        temp = temp + " ";
                    }
                    if(k>0){
                        temp = temp + " ";
                        k--;
                    }
                    temp = temp + words[j];
                }
            }
            else{
                temp = words[l];
                while(temp.length() < maxWidth){
                    temp = temp + " ";
                }
            }
            
            ans.push_back(temp);

        }

            int len = v[v.size()-1].first;
            int l = v[v.size()-1].second.first;
            int r = v[v.size()-1].second.second;
            int diff = r-l;
            

            temp = words[l];
            for(int j=l+1; j<=r; j++){
                temp = temp + " ";
                temp = temp + words[j];
            }
        
            
            while(temp.length() < maxWidth){
                temp = temp + " ";
            }
            
            
            ans.push_back(temp);



        return ans;

        

    }
};