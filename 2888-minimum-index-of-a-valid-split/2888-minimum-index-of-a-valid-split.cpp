class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int>mpr;
        for(int i=0; i<nums.size(); i++){
            mpr[nums[i]]++;
        }

        map<int,int>mpl;
        mpl[nums[0]]++;
        mpr[nums[0]]--;

        set<pair<int,int>>str;
        set<pair<int,int>>stl;

        for(auto i : mpr){
            if(i.second != 0){
                str.insert({i.second,i.first});
            }
        }

        for(auto i : mpl){
            if(i.second != 0){
                stl.insert({i.second,i.first});
            }
        }

        int n = nums.size();

        if(n==1) return -1;

        int k = (*stl.rbegin()).second;
        int p = (*str.rbegin()).second;
        int q = (*str.rbegin()).first;
        int r = (n-1)/2;

        if(k==p && q>r){
            return 0;
        }

        for(int i=1; i<n-1; i++){
            str.erase({mpr[nums[i]],nums[i]});
            mpr[nums[i]]--;
            if(mpr[nums[i]]>0)
            str.insert({mpr[nums[i]],nums[i]});

            stl.erase({mpl[nums[i]],nums[i]});
            mpl[nums[i]]++;
            stl.insert({mpl[nums[i]],nums[i]});

            int k = (*stl.rbegin()).second;
            int s = (*stl.rbegin()).first;
            int p = (*str.rbegin()).second;
            int q = (*str.rbegin()).first;

            // cout<<k<<" "<<s<<" "<<p<<" "<<q<<endl;
            
            if(k==p && s>(i+1)/2 && q>(n-i-1)/2){
                return i;
            }

        }


        return -1;


    }
};