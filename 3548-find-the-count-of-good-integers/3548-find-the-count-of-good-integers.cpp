class Solution {
    bool isdivisible(string &number, int k){
        if(stoll(number) % k == 0){
            return true;
        }
        return false;
    }
    long long int totalPalindrom(map<char,int>&frq , int n, vector<long long int>&fact){
        long long int count = fact[n];

        for(auto i : frq){
            // cout<<i.second<<" ";
            count = count / fact[i.second];
        }
        return count;
    }
    void findgoodpalindrom(int &n, string number, set<string>&st, vector<long long int>&fact, 
    int &k, long long int &k_palindrom){
        // cout<<number<<" ";
        if(!isdivisible(number,k)){
            return ;
        }

        sort(number.begin(), number.end());

        if(st.find(number) != st.end()){
            return ;
        }
        st.insert(number);

        map<char,int>frq;
        for(auto i : number){
            // cout<<i<<endl;
            frq[i]++;
        }

        long long int valid = totalPalindrom(frq,n,fact);
        long long int invalid = 0;

        if(frq['0'] > 0){
            frq['0']--;
            invalid = totalPalindrom(frq,n-1,fact);
        }
        k_palindrom += (valid - invalid);

        // cout<<k_palindrom<<" ";

        return ;
    }
    void findpalindrom(int pos , int &n,string &number, set<string>&st, vector<long long int>&fact, 
    int &k, long long int &k_palindrom){
        
        if(pos >= (n+1)/2){
            findgoodpalindrom(n,number,st,fact,k,k_palindrom);
            return ;
        }

        char start = (pos == 0)? '1' : '0';
        while(start <= '9'){
            number[pos] = start;
            number[n-pos-1] = start;
            findpalindrom(pos+1,n,number,st,fact,k,k_palindrom);
            start++;
        } 

        return ;
    }
public:
    long long countGoodIntegers(int n, int k) {
        vector<long long int>fact(11,1);
        for(int i=2; i<11; i++){
            fact[i] = fact[i-1]*i;
        }
        long long int k_palindrom = 0;
        set<string>st;
        string number(n,'0');

        findpalindrom(0,n,number,st,fact,k,k_palindrom);

        return k_palindrom;

    }
};