#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
/*
170. 两数之和 III - 数据结构设计

设计并实现一个 TwoSum 的类，使该类需要支持 add 和 find 的操作。
add 操作 -  对内部数据结构增加一个数。
find 操作 - 寻找内部数据结构中是否存在一对整数，使得两数之和与给定的数相等。

示例 1:   add(1); add(3); add(5);     find(4) -> true     find(7) -> false
示例 2:   add(3); add(1); add(2);     find(3) -> true     find(6) -> false
*/

class TwoSum {
private:
    unordered_map<int, int> mp;
public:
    /** Initialize your data structure here. */
    TwoSum() {}
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        mp[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto &it:mp) {
            if (mp.find(value - it.first) == mp.end()) continue;
            if (value - it.first == it.first && it.second == 1) continue;
            return true;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */