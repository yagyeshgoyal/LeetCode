class Solution {
    int mod = 1000000007;
    int findpow(int a , long long int n, map<int,int>&mp){
        if(n==1){
            return a;
        }

        if(mp.count(n)){
            return mp[n];
        }

        if(n%2 == 0){
            return mp[n] = (1ll*findpow(a,n/2,mp)*findpow(a,n/2,mp))%mod;
        }
        else{
            return mp[n] = (1ll*((1ll*findpow(a,n/2,mp)*findpow(a,n/2,mp))%mod)*a)%mod;
        }
    }
public:
    int countGoodNumbers(long long n) {
        long long int ans = 1;
        // for(int i=0; i<n; i++){
        //     if(i&1){
        //         ans = (ans * 4)%mod;
        //     }
        //     else{
        //         ans = (ans *5)%mod;
        //     }
        // }
        map<int,int>mp5;
        map<int,int>mp4;
        ans = (1ll*ans*findpow(5,(n+1)/2, mp5))%mod;
        if((n - ((n+1)/2)) >0)
        ans = (ans * findpow(4,(n - ((n+1)/2)), mp4))%mod;
        return ans;
    }
};