#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;
class LRUCache {
public:
    LRUCache(int capacity) {
        this->total_cap = capacity;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if(it == mp.end())
            return -1;
        pair<int,int>kv=*mp[key];
        cache.erase(mp[key]);
        cache.push_front(kv);
        mp[key] = cache.begin();
        return kv.second;
    }
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it==mp.end()){
            if(cache.size()==total_cap){
                auto lastPair = cache.back();
                int lastKey = lastPair.first;
                mp.erase(lastPair.first);
                cache.pop_back();
            }
            cache.push_front(make_pair(key, value));
            mp[key]=cache.begin();
        }
        else{
            cache.erase(mp[key]);
            cache.push_front(make_pair(key, value));
            mp[key]=cache.begin();
        }
    }
private:
    int total_cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */