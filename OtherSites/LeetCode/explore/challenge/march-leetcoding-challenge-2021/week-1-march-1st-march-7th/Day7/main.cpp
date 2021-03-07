#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
    set<pair<int,int>> vlst;
public:
    /** Initialize your data structure here. */
    MyHashMap() { vlst = set<pair<int,int>>(); }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto itr = vlst.lower_bound({ key, 0 });
        if (itr!=vlst.end() && itr->first==key) vlst.erase(itr);
        vlst.emplace(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto itr = vlst.lower_bound({ key, 0 });
        if (itr!=vlst.end() && itr->first==key) return itr->second;
        else return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto itr = vlst.lower_bound({ key, 0 });
        if (itr!=vlst.end() && itr->first==key) vlst.erase(itr);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(){
    return 0;
}
