/*

LRU Cache
Solution
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /// capacity /// );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
 
 */


class LRUCache {
public:
    list<int> q;
    unordered_map<int,int> cache_map_value;
    unordered_map<int,list<int>::iterator> cache_map;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cache_map_value.find(key) == cache_map_value.end())
            return -1;
        else{
            auto it = cache_map[key];
            int val = cache_map_value[key];
            q.erase(it);
            q.push_front(key);
            cache_map[key] = q.begin();
            return val;
        }
    }
    
    void put(int key, int value) {
        if(cache_map.find(key) == cache_map.end()){
            if(q.size() == cap){
                int key_to_rem = q.back();
                cache_map.erase(key_to_rem);
                cache_map_value.erase(key_to_rem);
                q.pop_back();
            }
            q.push_front(key);
            cache_map[key] = q.begin();
            cache_map_value[key] = value;
        }
        else{
            auto it = cache_map[key];
            q.erase(it);
            q.push_front(key);
            cache_map[key] = q.begin();
            cache_map_value[key] = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


