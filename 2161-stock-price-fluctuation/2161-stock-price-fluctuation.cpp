class StockPrice {
public:
    map<int,int>mp;
    multiset<int>st;
    set<int>st2;
    int curr = 0;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        curr = max(curr,timestamp);

        if(mp.count(timestamp)){
            auto it = st.find(mp[timestamp]);
            st.erase(it);
            st.insert(price);
            mp[timestamp] = price;
        }
        else{
            st.insert(price);
            mp[timestamp] = price;
        }
    }
    
    int current() {
        return mp[curr];
    }
    
    int maximum() {
        if(st.rbegin() != st.rend()){
            return *st.rbegin();
        }
        return -1;
    }
    
    int minimum() {
        return *st.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */