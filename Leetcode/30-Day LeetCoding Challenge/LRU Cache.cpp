class LRUCache {
public:
    vector<int> v;
    map<int ,int > m;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        if ( m.count(key)) {
            for ( int i =0 ; i < cap ;  i++){
                if (v[i] == key){
                    v.erase(v.begin() + i);
                    break;
                }
            }
            v.push_back(key);
            return m[key];
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if ( m.count(key)) {
             for ( int i =0 ; i < cap ;  i++){
                if (v[i] == key){
                    v.erase(v.begin() + i); 
                    break;
                }
            }  
        }
        else{
            if ( v.size() >= cap){ 
                m.erase(v[0]);
                v.erase(v.begin());
            }
        }
        v.push_back(key);
        m[key]= value;
    }
};
