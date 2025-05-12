class LRUCache {
public:
    vector<int>arr;
    int count = 1;
    map<int,int>mp;
    int size;
    LRUCache(int capacity) {
        size  = capacity;
        arr.resize(10001,-1);
    }
    
    int get(int key) {
        if(arr[key] == -1){
            return -1;
        }
        else{
            arr[key] = count;
            count++;
            return mp[key];
        }
    }
    
    void put(int key, int value) {
        if(arr[key] != -1){
            mp[key] = value;
            arr[key] = count++;
        }
        else if(size == 0){
            int k = INT_MAX;
            int p = -1;
            for(int i=0; i<arr.size(); i++){
                if(arr[i] != -1 && k>arr[i]){
                    k = arr[i];
                    p = i;
                }
            }
            arr[p] = -1;
            arr[key] = count++;
            mp[key] = value;
        }
        else{
            mp[key] = value;
            arr[key] = count++;
            size--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */