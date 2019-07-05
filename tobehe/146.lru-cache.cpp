/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */
class LRUCache {
public:
    LRUCache(int capacity) {
        _cap = capacity;
    }

    
    int get(int key) {
        auto it = _m.find(key);
        if(it == _m.end())
        {
            return -1;
        }

        int val = it->second->second;
        l.erase(it->second);
        l.push_front(make_pair(key,val));
        _m[key] = l.begin();
        return val;

    }
    
    void put(int key, int value) {
        auto it = _m.find(key);
        if(it!=_m.end())
        {
            l.erase(it->second);
        }

        l.push_front(make_pair(key,value));
        _m[key] = l.begin();
        int size = l.size();
        if(size > _cap)
        {
            _m.erase(l.back().first);
            l.pop_back();
        }

    }
private:
unordered_map<int , list<pair<int ,int>>::iterator> _m;
list<pair<int, int>> l;
int _cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

