class Solution {
public:

    int findans(int first , int last, vector<int>&arr, vector<int>&v, int target){
        int n = arr.size()-last;
        int leftsum = v[first+1];

        int s = arr[first];
        int e = arr[last];
        int mid = s + (e-s)/2;
        int ans = s;
        while(s<=e){
            int sum = leftsum + n*mid;
            if(abs(sum-target) < abs(leftsum + n*ans  - target)){
                ans = mid;
            }
            else if(abs(sum-target) == abs(leftsum + n*ans  - target)){
                ans = min(ans,mid);
            }

            if(sum==target){
                return mid;
            }
            else if(sum<target){
                s = mid+1;
                ans = mid;
            }
            else{
                e = mid-1;
            }

            mid = s + (e-s)/2;
        }

        return ans;
    }
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<int>v;
        v.push_back(0);
        for(int i=0; i<arr.size(); i++){
            v.push_back(v[v.size()-1] + arr[i]);
        }

        int first = -1;
        int last = -1;
        for(int i=0; i<arr.size(); i++){
            int a = v[i] + (arr.size()-i)*arr[i];
            if(a == target){
                return arr[i];
            }
            else if(a<target){
                first = i;
            }
            else{
                last = i;
                break;
            }
        }

        if(first == -1){
            int ans = target/arr.size();
            int first1 = ans*arr.size();
            int second = (ans+1)*arr.size();
            if(abs(first1-target)<=abs(second-target))
            return (target/arr.size());
            else
            return ans+1;
        }

        if(last == -1){
            return arr[arr.size() -1];
        }

        return findans(first, last, arr, v, target);
    }
};