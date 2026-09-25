class MyHashSet {
    vector<int> v;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        for(auto &i:v){
            if(i==key){
                return;
            }
        }
        v.push_back(key);
    }
    
    void remove(int key) {
        int n = v.size();
        for(int i=0;i<n;i++){
            if(v[i]==key){
                swap(v[i],v[n-1]);
                v.pop_back();
                return;
            }
        }
    }
    
    bool contains(int key) {
        for(auto &i:v){
            if(i==key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */