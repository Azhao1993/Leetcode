#include<iostream>
#include<vector>
using namespace std;
/*
432. 全 O(1) 的数据结构

实现一个数据结构支持以下操作：
Inc(key) - 插入一个新的值为 1 的 key。或者使一个存在的 key 增加一，保证 key 不为空字符串。
Dec(key) - 如果这个 key 的值是 1，那么把他从数据结构中移除掉。否者使一个存在的 key 值减一。如果这个 key 不存在，这个函数不做任何事情。key 保证不为空字符串。
GetMaxKey() - 返回 key 中值最大的任意一个。如果没有元素存在，返回一个空字符串""。
GetMinKey() - 返回 key 中值最小的任意一个。如果没有元素存在，返回一个空字符串""。
挑战：以 O(1) 的时间复杂度实现所有操作。
 */

class AllOne {
private:
    // 具有相同数值的放在一个Bucket中，buckets存放所有数据，bucketOfKey进行快速查找
    struct Bucket{int value; unordered_set<string> keys;};
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> bucketOfKey;
public:
    /** Initialize your data structure here. */
    AllOne() {
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        // 如果之前没有的话，插入一个为0的值，后面再＋1
        if(!bucketOfKey.count(key))
            bucketOfKey[key] = buckets.insert(buckets.begin(),{0,{key}});

        auto bucket = bucketOfKey[key], n = next(bucket);
        // 如果没有当前数值，则需要创建一个新的数
        if(n == buckets.end() || n->value > bucket->value+1)
            n = buckets.insert(n,{bucket->value+1,{}});
        // 加入数据到所有数据中，并加入hashmap中
        n->keys.insert(key);
        bucketOfKey[key] = n;

        // 把key为之前数值的记录删除，若为空则删除记录
        bucket->keys.erase(key);
        if(bucket->keys.empty())
            buckets.erase(bucket);
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        // 如果之前没有的话，直接返回
        if(!bucketOfKey.count(key))
            return ;

        auto bucket = bucketOfKey[key], p = prev(bucket);
        // 删除记录
        bucketOfKey.erase(key);

        if(bucket->value > 1){
            // 如果没有当前数值，则需要创建一个新的数
            if(bucket == buckets.begin() || p->value < bucket->value - 1)
                p = buckets.insert(bucket, {bucket->value-1,{}});
            p->keys.insert(key);
            bucketOfKey[key] = p;
        }


        // 把key为之前数值的记录删除，若为空则删除记录
        bucket->keys.erase(key);
        if(bucket->keys.empty())
            buckets.erase(bucket);
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());

    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
