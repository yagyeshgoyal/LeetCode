class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        vector<int>v(houses.size(), INT_MAX);
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        for(auto i : houses){
            cout<<i<<" ";
        }
        cout<<endl;
        
        map<int,int>mp;
        for(auto i : heaters){
            mp[i] = 1;
            cout<<i<<" ";
        }
        cout<<endl;

        int i=0;
        int heater = heaters[0];
        int j=1;

        while(i<houses.size()){
            while(j<heaters.size() && heaters[j] <=houses[i]){
                heater = heaters[j];
                j++;
            }

            if(houses[i] == heater){
                v[i] = 0;
            }
            else if(mp[houses[i]] == 1){
                v[i] = 0;
                heater = houses[i];
            }
            else{
                v[i] = min(v[i], abs(houses[i]-heater));
            }
            cout<<v[i]<<" ";
            i++;
        }
        cout<<endl;
        heater = heaters[heaters.size()-1];
        j = heaters.size()-2;
        i = houses.size()-1;
        int ans = 0;
        while(i>=0){
            while(j>=0 && heaters[j] >= houses[i]){
                heater = heaters[j];
                j--;
            }
            if(houses[i] == heater){
                v[i] = 0;
            }
            else if(mp[houses[i]] == 1){
                v[i] = 0;
                heater = houses[i];
            }
            else{
                v[i] = min(v[i], abs(houses[i]-heater));
            }
            cout<<v[i]<<" ";
            ans = max(ans, v[i]);
            i--;
        }

        return ans;
    }
};